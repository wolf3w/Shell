#include <errno.h>
#include <string.h>
#include "../headers/err1.h"

void err1 ()
{
	printf("%s\n",strerror(errno));
}
