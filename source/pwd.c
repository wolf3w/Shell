#include <stdio.h>
#include <unistd.h>
#include <limits.h> /* PATH_MAX  */

#include "../headers/pwd.h"
#include "../headers/err1.h"

void printdir ()
{
	char path[PATH_MAX];
	char *pn;

	pn = getwd(path);

	if (pn == NULL)
		err1();
	else
		printf("%s\n",path);
}
