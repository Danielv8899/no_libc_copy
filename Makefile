CC=gcc

copy:
	$(CC) -nostdlib copy.c mylibc.c -o copy