#include <stdio.h>
#include <unistd.h>

#include "../headers/cd.h"
#include "../headers/err1.h"

void changedir (char *path)
{
	if (chdir(path) == -1)
		err1();
	else
		printf("Directory changed\n");
}
