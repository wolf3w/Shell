#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../headers/df.h"
#include "../headers/err1.h"

void delfile (char *path)
{
	if ( unlink(path) == -1 ) {
		err1();
		return;
	}
	else
		printf("File deleting succesful\n");
}
