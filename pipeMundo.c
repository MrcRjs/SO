#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int p1;
	int estado;
	int fd[2];
	char buffer[30];
	pipe(fd);
	if(!(p1 = fork()))
	{
		buffer[5]='M';
		buffer[6]='u';
		buffer[7]='n';
		buffer[8]='d';
		buffer[9]='o';
		read(fd[0], buffer, 5);
		write(fd[1], buffer, 10);
		exit(0);
	}
	else{
		buffer[0]='H';
		buffer[1]='o';
		buffer[2]='l';
		buffer[3]='a';
		buffer[4]=' ';
		write(fd[1], buffer, 5);
		waitpid(p1, &estado, 0);
		read(fd[0], buffer, 10);
		printf("\n👾   👾   👾   👾   👾   👾   👾\n %s \n👾   👾   👾   👾   👾   👾   👾\n", buffer);
	}
}
