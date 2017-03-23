#include <string.h>
#include <stdio.h>

#include "../headers/err1.h"
#include "../headers/df.h"
#include "../headers/md.h"
#include "../headers/cp.h"
#include "../headers/of.h"
#include "../headers/rd.h"
#include "../headers/rf.h"
#include "../headers/stfile.h"
#include "../headers/help.h"

int main ()
{
	char path[255];
	char nname[255];
	char c[48];

	info();

	help_msg();


	while (1) {

		printf("\n\033[31;40;1m>>\033[m");

		scanf("%48s",c);
		
		if (strcmp(c, "exit") == 0)
			return 0;

		else if (strcmp(c, "del-f") == 0) {
			printf("Enter path name:\nPath>");
			scanf("%255s",path);
			delfile(path);
		}

		else if (strcmp(c, "op-f") == 0) {
			printf("Enter path name:\nPath>");
			scanf("%255s",path);
			openfile(path);
		}

		else if (strcmp(c, "st-f") == 0) {
			printf("Enter path name:\nPath>");
			scanf("%255s",path);
			statfile(path);
		}
		
		else if (strcmp(c, "cp-f") == 0) {
			printf("Enter path name:\nPath>");
			scanf("%255s",path);
			printf("Enter NEW name:\nNew>");
			scanf("%255s",nname);
			copyfile(path, nname);
		}

		else if (strcmp(c, "rn-f") == 0) {
			printf("Enter path name:\nPath>");
			scanf("%255s",path);
			printf("Enter NEW name:\nNew>");
			scanf("%255s",nname);
			renamefile(path, nname);
		}

		else if (strcmp(c, "del-d") == 0) {
			printf("Enter path name:\nPath>");
			scanf("%255s",path);
			deldir(path);
		}

		else if (strcmp(c, "cr-d") == 0) {
			printf("Enter path name:\nPath>");
			scanf("%255s",path);
			makedir(path);
		}

		else if (strcmp(c, "help") == 0) {
			help_msg();
		}

		else {
			printf("Unknown command. Enter 'help' to display a list of commands.\n");
		}

	}
}
















