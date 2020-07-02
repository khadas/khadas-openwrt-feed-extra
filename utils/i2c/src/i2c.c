
// ## hyphop ##

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	char filename[32];
	//char i2c_addr = 0x3c;
	unsigned char i2c_addr;

	//fprintf( stderr, "args %d\n", argc );

	if ( argc > 1 ) {
	    if ( !strcmp (argv[1], "--help" )) {
		fprintf( stderr, "USAGE i2c [dev] [addr] < hexdata_by_line\n" );
		exit(0);
	    }
	    sprintf(filename, argv[1]);
	} else {
	    sprintf(filename, "/dev/i2c-0");
	}
	
	if ( argc > 2 ) {
	    sscanf( argv[2], "%2hhx", &i2c_addr );
	} else {
	    //sscanf( "3c", "%2hhx", &i2c_addr );
	    i2c_addr = 0x3c;
	}

	int file;

	file = open(filename, O_RDWR);

	if (file < 0) {
	    fprintf ( stderr, "i2c error open %s \n", filename );
	    return -1;
	}

	if (ioctl( file, I2C_SLAVE, i2c_addr ) < 0) { 
	    fprintf ( stderr, "i2c error bind %s => %02x\n", filename, i2c_addr );
	    return -2;
	}


	if (  argc > 3 ) { // some debug
	    fprintf ( stderr, "i2c open %s => %02x\n", filename, i2c_addr );
	}

	freopen(NULL, "rb", stdin);
	freopen(NULL, "rb", stdout);
	freopen(NULL, "rb", stderr);

	unsigned char buffer[2048];

	char * line = NULL;
	
        size_t len = 0;
	ssize_t read;

	int s;

        while ((read = getline(&line, &len, stdin)) != -1) {

	    s = (read / 2);
	    int i;
	    for ( i = 0 ; i < s ; i++ ){
		sscanf( line + 2*i , "%2hhx", &buffer[i] );
	    }

	    if (  argc > 3 ) { // some debug
		fprintf ( stderr, "i2c write %s => %d %d %d %d\n", line, s, len, read, i );
	    }

//i2c write 80ae
// => 2 7 5 2

	    int r;
	    r = write( file , buffer , s );
//
	    if (r > 0 ) {
		;;
	    }
	}

        if (line) free(line);
	
	return 0;

}

