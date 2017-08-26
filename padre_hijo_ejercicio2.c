#include<stdio.h>
#include<stdlib.h>

int main() {
  // int pid;
  // printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
  // pid = fork();
  // En cuanto llamamos a fork se crea un nuevo proceso. En el proceso
  // padre 'pid' contendrá el pid del proceso hijo. En el proceso hijo
  // 'pid' valdrá 0. Eso es lo que usamos para distinguir si el código
  // que se está ejecutando pertenece al padre o al hijo.
  /*if (pid) // Este es el proceso padre
  {
    printf("PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
    printf("PADRE: Mi hijo tiene el pid: %d\n", pid);
  }
  else // Proceso hijo
  {
    printf("HIJO: Soy el proceso hijo y mi pid es: %d\n", getpid());
    printf("HIJO: mi padre tiene el pid: %d\n", getppid());
  }*/
  int hijoA, hijoB;
  hijoA = fork();
  if(hijoA > 0)
  {
    hijoB = fork();
    if(hijoB > 0)
    {
      printf("Main Pid: %d\n", getpid() );
    }
    else
    {
      int hijoB1;
      hijoB1 = fork();
      if(hijoB1 > 0)
      {
        printf("B: PPid %d Pid %d\n", getppid(), getpid() );
      }
      else
      {
        printf("B1: PPid %d Pid %d\n", getppid(), getpid() );
      }
    }
  }
  else
  {
    int hijoA1;
    hijoA1 = fork();
    if(hijoA1 > 0)
    {
      printf("A: PPid %d Pid %d\n", getppid(), getpid() );
    }
    else
    {
      printf("A1: PPid %d Pid %d\n", getppid(), getpid() );
    }
  }
}