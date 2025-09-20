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
            exit(15);
        }

        int pid_2 = fork();
        if (pid_2 < 0) {
            perror("fork");
        }
            
        if(pid_2 == 0) {
	    int x = 0;
            int v = 10/x; 
	    exit(25);

        }
        waitpid(pid_1,&status,0);
        if (WIFEXITED(status)) {
            printf ("Normal termination of child 1 with exit status=%d\n",WEXITSTATUS (status));
        }
        else{
            printf("Child 2 Abnormal termination of child 1\n");
        }
        waitpid(pid_2, &status, 0);
        if (WIFEXITED(status)) {
            printf ("Normal termination of child 2 with exit status=%d\n",WEXITSTATUS (status));
        }
         else{
            printf("Child 2 Abnormal termination of child 2\n");
        }
} 
