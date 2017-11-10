//Llamada a librerías
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
//Función principal
main(int argc, char **argv[])
{
//Declaramos variables
int fd;
char *c;
//CREAR ARCHIVO
//O_WRONLY abre el archivo salida.txt en modo escritura
//O_CREAT crea el archivo si todavía no existe
//S_IRUSR|S_IWUSR son los modos que seleccione: Lectura y Escritura para el usuario
fd = open("salida3.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
//fd = open("salida1.txt",O_WRONLY|00700);
 
//Ingresamos por teclado lo que queremos guardar en el archivo
scanf("%s",&c);
 
printf("el tamanho del string es %d\n",sizeof(c));
 
//Guardamos en el archivo lo que ingresamos por teclado
write(fd,&c,sizeof(c));
 
//CERRAR ARCHIVO
close(fd);
 
}