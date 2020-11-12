/*
 * zerofree - a tool to zero free blocks in an ext[2-4] filesystem
 *
 * Copyright (C) 2004-2017 R M Yorston
 *
 * This file may be redistributed under the terms of the GNU General Public
 * License, version 2.
 *
 * Changes:
 *
 * 2020-11-12  fix build for musl and fix Makefile for openwrt build
 *             by Artem Lapkin ## hyphop ##
 * 2017-02-22  Lift call to ext2fs_free_blocks_count out of loop.  Suggested
 *             by Thanassis Tsiodras.
 * 2016-02-18  Add support for 64-bit block numbers.
 * 2015-10-18  Use memcmp.  Suggested by Damien Clark.
 * 2010-10-17  Allow non-zero fill value.   Patch from Jacob Nevins.
 * 2007-08-12  Allow use on filesystems mounted read-only.   Patch from
 *             Jan Krämer.
 */

#include <sys/types.h>
#include <ext2fs/ext2fs.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#if defined(EXT2_FLAG_64BITS)
#define FLAGS (EXT2_FLAG_RW|EXT2_FLAG_64BITS)
#define FORMAT "\r%llu/%llu/%llu\n"
#else
#define FLAGS EXT2_FLAG_RW
#define blk64_t blk_t
#define ext2fs_blocks_count(s) ((s)->s_blocks_count)
#define ext2fs_free_blocks_count(s) ((s)->s_free_blocks_count)
#define ext2fs_test_block_bitmap2(m,b) ext2fs_test_block_bitmap(m,b)
#define io_channel_read_blk64(c,b,n,d) io_channel_read_blk(c,b,n,d)
#define io_channel_write_blk64(c,b,n,d) io_channel_write_blk(c,b,n,d)
#define FORMAT "\r%lu/%lu/%lu\n"
#endif

#define USAGE "usage: %s [-n] [-v] [-f fillval] filesystem\n"

int main(int argc, char **argv)
{
	errcode_t ret;
	int flags;
	int superblock = 0;
	int open_flags = FLAGS;
	int blocksize = 0;
	ext2_filsys fs = NULL;
	blk64_t blk, free, modified;
	unsigned char *buf;
	unsigned char *empty;
	int c;
	double percent, freeBlocks;
	int old_percent;
	unsigned int fillval = 0;
	int verbose = 0;
	int dryrun = 0;

	while ( (c=getopt(argc, argv, "nvf:")) != -1 ) {
		switch (c) {
		case 'n' :
			dryrun = 1;
			break;
		case 'v' :
			verbose = 1;
			break;
		case 'f' :
			{
				char *endptr;
				fillval = strtol(optarg, &endptr, 0);
				if ( !*optarg || *endptr ) {
					fprintf(stderr, "%s: invalid argument to -f\n", argv[0]);
					return 1;
				} else if ( fillval > 0xFFu ) {
					fprintf(stderr, "%s: fill value must be 0-255\n", argv[0]);
					return 1;
				}
			}
			break;
		default :
			fprintf(stderr, USAGE, argv[0]);
			return 1;
		}
	}

	if ( argc != optind+1 ) {
		fprintf(stderr, USAGE, argv[0]);
		return 1;
	}

	ret = ext2fs_check_if_mounted(argv[optind], &flags);
	if ( ret ) {
		fprintf(stderr, "%s: failed to determine filesystem mount state  %s\n",
					argv[0], argv[optind]);
		return 1;
	}

	if ( (flags & EXT2_MF_MOUNTED) && !(flags & EXT2_MF_READONLY) ) {
		fprintf(stderr, "%s: filesystem %s is mounted rw\n",
					argv[0], argv[optind]);
		return 1;
	}

	ret = ext2fs_open(argv[optind], open_flags, superblock, blocksize,
							unix_io_manager, &fs);
	if ( ret ) {
		fprintf(stderr, "%s: failed to open filesystem %s\n",
					argv[0], argv[optind]);
		return 1;
	}

	empty = (unsigned char *)malloc(fs->blocksize);
	buf = (unsigned char *)malloc(fs->blocksize);

	if ( empty == NULL || buf == NULL ) {
		fprintf(stderr, "%s: out of memory (surely not?)\n", argv[0]);
		return 1;
	}

	memset(empty, fillval, fs->blocksize);

	ret = ext2fs_read_block_bitmap(fs);
	if ( ret ) {
		fprintf(stderr, "%s: error while reading block bitmap\n", argv[0]);
		return 1;
	}

	free = modified = 0;
	percent = 0.0;
	freeBlocks = (double)ext2fs_free_blocks_count(fs->super);
	old_percent = -1;

	if ( verbose ) {
		fprintf(stderr, "\r%4.1f%%", percent);
	}

	for ( blk=fs->super->s_first_data_block;
			blk < ext2fs_blocks_count(fs->super); blk++ ) {

		if ( ext2fs_test_block_bitmap2(fs->block_map, blk) ) {
			continue;
		}

		++free;

		percent = 100.0 * (double)free/freeBlocks;

		if ( verbose && (int)(percent*10) != old_percent ) {
			fprintf(stderr, "\r%4.1f%%", percent);
			old_percent = (int)(percent*10);
		}

		ret = io_channel_read_blk64(fs->io, blk, 1, buf);
		if ( ret ) {
			fprintf(stderr, "%s: error while reading block\n", argv[0]);
			return 1;
		}

		if ( !memcmp(buf, empty, fs->blocksize) ) {
			continue;
		}

		++modified;

		if ( !dryrun ) {
			ret = io_channel_write_blk64(fs->io, blk, 1, empty);
			if ( ret ) {
				fprintf(stderr, "%s: error while writing block\n", argv[0]);
				return 1;
			}
		}
	}

	if ( verbose ) {
		printf(FORMAT, modified, free, ext2fs_blocks_count(fs->super));
	}

	ret = ext2fs_close(fs);
	if ( ret ) {
		fprintf(stderr, "%s: error while closing filesystem\n", argv[0]);
		return 1;
	}

	return 0;
}
