// ## hyphop ##

/* USAGE

/tmp/spi /dev/mtdblock0 < VIM3.krescue.spi.img

*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define bs 4096

char buf[bs];
char bu2[bs];

size_t r;
int out;

int rate=1;
int rewrited=0;
int same=0;
int total=0;

// gzip -dc VIM2.krescue.spi.img.gz | RATE=10 spiupdate /dev/mtdblock0  ; echo $?

int main(int argc, char *argv[]) {

    const char* SIZE = getenv("SIZE");
    int size=bs*bs;
    const char* RATE = getenv("RATE");
    if (RATE) rate=atoi(RATE);
    if (SIZE) size=atoi(SIZE);
    int blocks = size / bs;
    fprintf(stderr,"[i] spiupdate => %s (%d - %d)\n", argv[1], size, blocks);
    fprintf(stdout, "###  all blks wrtd same\n");
    
    out = open(argv[1], O_RDWR);
    if ( out < 0) return 1;

while( memset( buf, 0, bs) && ( read(0, buf, bs) > 0 ) )
{

    r =  ftell(stdin);
    memset( bu2, 0, bs);
    r = read(out,bu2,bs);

    if ( r < 1) return 2;

    if ( memcmp( buf, bu2, bs) ) {
	if ( lseek(out, -bs, 1) < 0 ) return 3;
	if ( write(out, buf, bs) < 1 ) return 4;
	fsync(out);
	rewrited++;
    } else {
	same++;
    }

    total++;
    if ( !( total % rate)  ) \
    fprintf(stdout, "%03d %04d %04d %04d %04d\r", 100*total/blocks, \
	total, blocks, rewrited, same);

}

    fprintf(stdout, "\n" );

if ( close(out) < 0 ) return 5;
// done
return 0;

}

