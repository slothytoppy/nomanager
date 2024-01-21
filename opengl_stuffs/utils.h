#ifndef UTILS_H
#define UTILS_H


#include <stdio.h>

#include <sys/wait.h>
#include <unistd.h>

unsigned int run_args(char* pathname[]){
	if(!pathname) return 0;
	pid_t id=fork();
	int child_status;
	if(id==0){
		if(!execv(pathname[0], pathname)){
			perror("exec");
		}
	} 
	if(id<0){
		perror("forking");
		return 0;
	}
	wait(&child_status);
	return 1;
}

unsigned int run(char* pathname){ // from nomake.h but i added it here for one less dependency
	if(!pathname) return 0;
	char* command[]={pathname, NULL};
	if(run_args(command)){
		return 1;
	}
	return 0;
}

#endif
