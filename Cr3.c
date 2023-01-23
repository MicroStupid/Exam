#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
 
int main() {
    pid_t pid = fork();
 
    if (pid == -1) {
        fprintf(stderr, "Unable to fork\n");
    } else if (pid > 0) {
        printf("I am parent %d\n", getpid());
        printf("Child is %d\n", pid);
        int status;
        // wait(&status);
        waitpid(pid, &status, 0);
        printf("Wait OK\n");
    } else {
        // we are the child            
        printf("I am child %d of %d\n", getpid(), getppid());
        if (execlp("./hl", "hl", NULL) == -1) {
            fprintf(stderr, "Unable to exec\n");
        }
    }
}