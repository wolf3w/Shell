#include <stdio.h>

#include "../headers/help.h"

void help_msg ()
{
	printf("For delete file put: \033[4;33;40;1mdel-f\033[m\n");
	printf("Open file: \033[4;33;40;1mop-f\033[m\n");
	printf("Withdraw file stats: \033[4;33;40;1mst-f\033[m\n");
	printf("Copy file: \033[4;33;40;1mcp-f\033[m\n");
	printf("Rename file: \033[4;33;40;1mrn-f\033[m\n");
	printf("Delete directory: \033[4;33;40;1mdel-d\033[m\n");
	printf("Create directory: \033[4;33;40;1mcr-d\033[m\n");
	printf("Show this help message: \033[4;33;40;1mhelp\033[m\n");
	printf("If you want exit type: \033[4;33;40;1mexit\033[m\n");
}

void info ()
{
	printf("\033[37;40;1m========== BSU Shell version 0.2 ==========\033[m\n");
}
