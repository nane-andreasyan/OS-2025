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
            printf("Child process created\n");
            exit(0);
        }
	wait(NULL);
        sleep(30);

}
