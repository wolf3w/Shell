#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#include "../headers/ls.h"
#include "../headers/err1.h"

void listdir ()
{
	DIR  *dptr;
	struct dirent *ds;

	if ((dptr = opendir(".")) == NULL)
		err1();
	
	while ((ds = readdir(dptr)) != 0) {
		if (ds -> d_name[0] == '.')
			continue;

		printf("%s\n", ds -> d_name);
	}

	closedir(dptr);
}
