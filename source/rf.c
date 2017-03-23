#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../headers/rf.h"
#include "../headers/err1.h"

#define BS 1

char buf1[1];

void renamefile (char *path, char *nname)
{
	int i = 0, ffd, sfd;
	ssize_t count;

	ffd = open(path, O_RDONLY);

	if (ffd == -1)
		err1();

	sfd = open(nname, O_WRONLY | O_CREAT | O_EXCL, 0644);
	
	if (sfd == -1)
		err1();
	while ((count = read(ffd,buf1,BS)) > 0) {
		write(sfd, buf1, count);
		i++;
	}

	if (count == -1)
		err1();
	printf("Copy succesfull\nBytes copyed:%d\n",i);
	
	close(ffd);
	
	if (unlink(path) == -1)
		err1();
	printf("Source file delete\n");

	close(sfd);
}
