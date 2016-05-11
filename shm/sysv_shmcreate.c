/*
 * =====================================================================================
 *
 *       Filename:  sysv_shm_test.c
 *
 *    Description:  system V 共享内存读
 *
 *        Version:  1.0
 *        Created:  2016年05月11日 08时15分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:	houbin , houbin-12@163.com
 *   Organization:  Houbin, Inc. ShangHai CN. All rights reserved.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>

#include <sys/shm.h>
#include <sys/ipc.h>
#include <fcntl.h>

#define SVSHM_MODE (SHM_R | SHM_W | SHM_R>>3 | SHM_R>>6)

int main(int argc, char* argv[])
{
	int c, id, oflag;
	char *ptr;
	size_t length;

	oflag = SVSHM_MODE | IPC_CREAT;
	while ((c == getopt(argc, argv, "e")) != -1) {
		switch (c) {
			case 'e':
				oflag |= IPC_EXCL;
				break;
		}
	}
	if (optind != argc - 2) {
		printf("usage: shmget [ -e ] <pathname> <length>");
		return 1;
	}
	length = atoi(argv[optind + 1]);

	id = shmget(ftok(argv[optind], 0), length, oflag);
	ptr = shmat(id, NULL, 0);

	return 0;
}

