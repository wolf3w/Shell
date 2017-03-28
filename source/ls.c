#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#include "../headers/ls.h"
#include "../headers/err1.h"

void listdir ()
{
	DIR  *dptr;
	struct dirent *ds;
	struct stat st;

	if ((dptr = opendir(".")) == NULL)
		err1();
	
	while ((ds = readdir(dptr)) != 0) {
		if (ds -> d_name[0] == '.')
			continue;
	
		if (stat(ds -> d_name, &st) == -1)
			err1();

		if ((st.st_mode & S_IFMT) == S_IFDIR) 
			printf("\033[34;40;1m%s\033[m\n", ds -> d_name);
		if ((st.st_mode & S_IFMT) == S_IFREG)
			printf("\033[37;40;1m%s\033[m\n", ds -> d_name);
	}

	closedir(dptr);
}
