#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#include "../headers/rd.h"
#include "../headers/err1.h"

void deldir (char *path)
{
	DIR *dir;
	int u;
	struct dirent *sdir;

	dir = opendir(path);

	if (dir == NULL)
		err1();
	chdir(path);

	while ((sdir = readdir(dir)) != NULL) {
		u = unlink(sdir -> d_name);

		if (u == -1 && errno == EISDIR) {
			if ( (strcmp(".", sdir -> d_name) == 0) || (strcmp("..",sdir -> d_name) == 0) )
				continue;
			deldir(sdir -> d_name);
		}

		if (u == -1 && errno == EISDIR)
			err1();
	}
	closedir(dir);

	chdir("..");

	if (rmdir(path) == NULL)
		err1();
}






