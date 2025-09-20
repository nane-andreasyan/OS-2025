#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() 
{       int status;
        int pid_1 = fork();
        if (pid_1 < 0) {
            perror("fork");
        }

        if(pid_1 == 0) {
            printf("In child process 1\n");
            exit(0);
        }

        int pid_2 = fork();
        if (pid_2 < 0) {
            perror("fork");
        }
            
        if(pid_2 == 0) {
            printf("In child process 2\n");
            exit(30);

        }
        waitpid(pid_2,&status,0);
        if (WIFEXITED(status)) {
            printf ("Normal termination of child 2 with exit status=%d\n",WEXITSTATUS (status));
        }
        wait(&status);
        if (WIFEXITED(status)) {
            printf ("Normal termination of child 1 with exit status=%d\n",WEXITSTATUS (status));
        }
} 
