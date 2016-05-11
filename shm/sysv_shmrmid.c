/*
 * =====================================================================================
 *
 *       Filename:  sysv_shmrmid.c
 *
 *    Description: system v shm delete
 *
 *        Version:  1.0
 *        Created:  2016年05月11日 08时42分28秒
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
	int id;
	if (argc != 2) {
		printf("usage : shmrmid <pathname>");
		return 1;
	}

	id = shmget(ftok(argv[1], 0), 0, SVSHM_MODE);
	shmctl(id, IPC_RMID, NULL);

	return 0;
}

