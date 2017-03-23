#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../headers/err1.h"
#include "../headers/of.h"

#define BUFSIZE 256

void openfile (char *path)
{
	int fd;
	int n;
	char buf[BUFSIZE];

	if ((fd = open(path,O_CREAT,S_IRWXU)) == -1)
		err1();
	else 
		printf("File opening/creation succesfull:\n");

	while ((n = read(fd, buf, BUFSIZE)) > 0)
		write(1, buf, n);
	
	close(fd);
}
