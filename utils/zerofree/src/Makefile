#CC=gcc

all: zerofree.c
	$(CC) $(CFLAGS) -o zerofree zerofree.c -lext2fs -lcom_err

clean:
	/bin/rm -f *.o *~ zerofree
