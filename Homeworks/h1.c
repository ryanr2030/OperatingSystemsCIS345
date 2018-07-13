#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
	int fd1[2], fd2[2];
	int pid, pid1;

	if (pipe(fd1)<0){
		perror("Pipe Failed");	
		return -1;
	}

	if (pipe(fd2)<0){
		perror("Pipe Failed");	
		return -1;
	}
	

	pid = fork();
	
	if (pid==0){
	close(fd1[0]);
	printf("Message from Child 2: RECEIVED\n");
	close(fd1[1]);
	}
	
	else if (pid>0){
	close(fd1[0]);
	printf("Hi, I am your parent from CIS 345.\n");	
	close(fd1[1]);
	wait(NULL);
        exit(0);
	}
	
	pid1 = fork();
	
	if (pid1==0){
	close(fd2[0]);
	printf("Message from Child 2: RECEIVED\n");
	close(fd2[1]);
	}
	
	else if (pid1>0){
	close(fd2[0]);
	printf("Hi, I am your parent from CIS 345.\n");	
	close(fd2[1]);
	wait(NULL);
        exit(0);
	}
	
}

