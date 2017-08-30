#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
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
  if( argc == 3 ) {

    int x = strtol(argv[1], NULL, 0);
    int y = strtol(argv[2], NULL, 0);
    printf("X: %d\n", x);
    printf("Y: %d\n", y);

    int pXSmaller, pXGreater;
    pXSmaller = fork();

    if(pXSmaller > 0 && x < y)
    {
      pXGreater = fork();
      if(pXGreater > 0)
      {
        //printf("Main Pid: %d\n", getpid() );
      }
      else
      {
        int hijoB1, hijoB2;
        hijoB1 = fork();
        // X smaller than Y
        if(hijoB1 > 0 && x < y)
        {
          hijoB2 = fork();
          if(hijoB2 > 0)
          {
            printf("X is smaller than Y\n");
          }
          else
          {
            printf("X + Y: %d\n", x + y );
          }
        }
        else
        {
          printf("X * Y: %d\n", x * y );
        }
      }
    }
    else if(x > y)
    {
      int hijoA1, hijoA2;
      hijoA1 = fork();
      if(hijoA1 > 0 && x > y)
      {
        hijoA2 = fork();
        if(hijoA2 > 0)
        {
          printf("X is greater than Y\n");
        }
        else
        {
          printf("X - Y: %d\n", x - y );
        }
      }
      else
      {
        printf("X / Y: %d\n", x / y );
      }
    }
  } else {
    printf("Expected X and Y arguments.\n");
  }
  return 0;
}