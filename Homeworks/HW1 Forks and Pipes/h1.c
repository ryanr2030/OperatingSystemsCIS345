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
	int count=1, nbytes;
	int fd1[4], fd2[4];
	int pid, pid1;
	char string[]="Hi, I am your parent from CIS 345.";
	char string2[]="Message from Child 1: RECEIVED";
	char readbuffer[80], rb[80];

for(int i=0; i<2; ++i){
	if (pipe(fd1+(i*2))<0){
		perror("Pipe Failed");	
		return -1;
	}

	if (pipe(fd2+(i*2))<0){
		perror("Pipe Failed");	
		return -1;
	}
}

	pid = fork();
	
	//child
	if (pid==0){
		//close pipe 1
		close(fd1[0]);
		close(fd1[3]);
		read(fd1[2], rb, strlen(string)+1);
 		printf("%s\n", rb);
		write(fd1[1],"Message from Child P2: RECEIVED", (strlen(string2)+1));
			
	
	

	
	}
	
	else if (pid>0){
	close(fd1[1]);
	close(fd1[2]);

	write(fd1[3],string, (strlen(string)+1)); 	
	read(fd1[0], readbuffer, (strlen(string)+1));
	printf("%s\n\n", readbuffer);
	
	close(fd1[3]);
	close(fd1[0]);
	wait(NULL);

        exit(0);
	}
	
	pid1 = fork();
		if (pid1==0){
		close(fd2[0]);
		close(fd2[3]);
		read(fd2[2], rb, strlen(rb)+1);
 		printf("%s\n", rb);
		write(fd2[1],"Message from Child P3: RECEIVED", (strlen(string2)+1));
			
	
	

	
	}
	
	else if (pid1>0){
	close(fd2[1]);
	close(fd2[2]);

	write(fd2[3],string, (strlen(string)+1)); 	
	read(fd2[0], readbuffer, (strlen(string)+1));
	printf("%s\n\n", readbuffer);
	
	close(fd2[3]);
	close(fd2[0]);
	wait(NULL);

        exit(0);
	}

	
}

