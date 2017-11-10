#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main(){

	pid_t ID_Padre;
	pid_t ID_Hijo1;
	pid_t ID_Hijo2;
	pid_t ID_Hijo3;
	pid_t ID_Nieto1;
	pid_t ID_Nieto2;
	pid_t ID_Nieto3;
	pid_t ID_Nieto4;
	pid_t ID_Nieto5;
	int estado;

	if( (ID_Hijo1=fork()) ){
		waitpid(ID_Hijo1,&estado,0);

		// Hijo2
		if( (ID_Hijo2=fork()) ){
			waitpid(ID_Hijo2,&estado,0);
		}
		else{
			if( (ID_Nieto3=fork()) ){
				waitpid(ID_Nieto3,&estado,0);
				if( (ID_Nieto4=fork()) ){
					waitpid(ID_Nieto4,&estado,0);
				}
else {
	// Nieto3
	printf("M\n");
	printf("Hola soy el proceso NIETO 3 mi pid es %d\n",getpid());
	printf("NIETO 3  mi padre tiene el PID %d \n", getppid());
	exit(0);
}
}
else{
	//Nieto4
	printf("A\n");
	printf("Hola soy el proceso  NIETO 4 mi pid es: %d \n",getpid());
	printf("NIETO 4: mi padre tiene el PID: %d \n", getppid());
	exit(0);
}

printf("U\n");
printf("Hola soy el proceso Hijo 2 mi pid es %d\n",getpid());
printf("Hijo 2 mi padre tiene el PID %d \n", getppid());
exit(0);
}

// Hijo3
if( (ID_Hijo3=fork()) ){
	waitpid(ID_Hijo3,&estado,0);
}
else{
	if( (ID_Nieto5=fork()) ){
		waitpid(ID_Nieto5,&estado,0);
	}
	else{
		printf("N\n");
		printf("Hola soy el proceso  NIETO 5 mi pid es: %d \n",getpid());
		printf("NIETO 5: mi padre tiene el PID: %d \n", getppid());
		exit(0);
	}
	printf("D\n");
	printf("Hola soy el proceso Hijo 3 mi pid es %d\n",getpid());
	printf("Hijo 3 mi padre tiene el PID %d \n", getppid());
	exit(0);
}

// Padre
printf("O\n");
printf("Soy el padre mi pid es: %d \n",getpid());

}
else{
	if( (ID_Nieto1=fork()) ){
		// Nieto 1
		waitpid(ID_Nieto1,&estado,0);

	if( (ID_Nieto2=fork()) ){
		// Nieto 2
		waitpid(ID_Nieto2,&estado,0);
}
else{
	printf("O\n");
	printf("Hola soy el proceso NIETO 2 mi pid es %d\n",getpid());
	printf("NIETO 2  mi padre tiene el PID %d \n", getppid());
	exit(0);
}
}
else{
	printf("H\n");
	printf("Hola soy el proceso NIETO 1 mi pid es: %d \n",getpid());
	printf("NIETO 1: mi padre tiene el PID: %d \n", getppid());
	exit(0);
}
printf("L\n");
printf("Hola soy el proceso HIJO 1 mi pid es: %d \n", getpid());
printf("HIJO 1: mi padre tiene el PID: %d \n", getppid());
exit(0);
}
}
