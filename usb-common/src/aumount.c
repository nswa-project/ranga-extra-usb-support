#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700
#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mount.h>
#include <pthread.h>

static volatile int res = 0;

static void *worker(void *arg)
{
	char *target = (char *) arg;
	if (umount(target) < 0) {
		switch (errno) {
		case EBUSY:
			res = 8;
			break;
		default:
			res = 1;
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2)
		printf("Usage: %s <target>\n", argv[0]), exit(1);

	pthread_t tid;
	pthread_create(&tid, NULL, worker, (void *) argv[1]);

	sleep(2);
	exit(res);
}
