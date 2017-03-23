#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "../headers/stfile.h"
#include "../headers/err1.h"

void statfile (char *path)
{
	struct stat sb;

	if (stat(path, &sb)	== -1)
		err1();
	else {
		printf("File type:\n");

		switch (sb.st_mode & S_IFMT) {

			case S_IFBLK : 
				printf("Block device\n");
				break;
			case S_IFCHR :
				printf("Character device\n");
				break;
			case S_IFDIR :
				printf("Directory\n");
				break;
			case S_IFIFO :
				printf("FIFO /pipe\n");
				break;
			case S_IFLNK :
				printf("Symlink\n");
				break;
			case S_IFREG :
				printf("Regular file\n");
				break;
			case S_IFSOCK :
				printf("Socket\n");
				break;
			default :
				printf("Unknown?\n");
				break;
		}

		printf("i-node number:%ld\n", (long) sb.st_ino);
		
		printf("Mode: %lo(octal)\n", (unsigned long) sb.st_mode);
		
		/* Permission */
		if (sb.st_mode & S_IRUSR)
			printf("Owner has read permission\n");
		if (sb.st_mode & S_IWUSR)
			printf("Owner has write permission\n");			
		if (sb.st_mode & S_IXUSR & !S_IFDIR)
			printf("Owner has execute permission\n");
		if (sb.st_mode & S_IRGRP)
			printf("Group has read permission\n");
		if (sb.st_mode & S_IWGRP)
			printf("Group has write permission\n");
		if (sb.st_mode & S_IXGRP & !S_IFDIR)
			printf("Group has execute permission\n");
		if (sb.st_mode & S_IROTH)
			printf("Others have read permission\n");
		if (sb.st_mode & S_IWOTH)
			printf("Others have write permission\n");
		if (sb.st_mode & S_IXOTH & !S_IFDIR)
			printf("Others have execute permission\n");

		printf("Link count: %ld\n", (long) sb.st_nlink);

		printf("Ownership: UID = %ld  GID = %ld\n", (long) sb.st_uid, (long) sb.st_gid);

		printf("Preferred I/O block size: %ld bytes\n", (long) sb.st_blksize);

		printf("File size: %lld bytes\n", (long long) sb.st_size);

		printf("Blocks allocated: %lld\n", (long long) sb.st_blocks);
	}
}








