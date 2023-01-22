#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int pid;
	pid = fork();
	if (pid == -1)
	{
	perror("fork"); exit(1);
	}
	if (pid == 0)
	{
	printf("Потомок %d\n", pid);
	}
	else
	{
	printf("Родитель %d\n", pid) ;
	}
}