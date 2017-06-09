#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main()
{
	int x=3;
	printf("PADRE:  %d \n",x);
	if(fork()==0)
	{
		x= 8;
		printf("HIJO:  %d \n",x);
		exit(0);	
	}
	else{
		sleep(3);
		printf("PADRE:  %d \n",x);
	}

}
