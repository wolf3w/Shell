#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "../headers/md.h"
#include "../headers/err1.h"

void makedir (char *path)
{
	if ( mkdir(path, 0777) == 0 )
		printf("Directory created\n");
	else
		err1();
}
