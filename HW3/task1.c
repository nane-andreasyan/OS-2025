#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() 
{ 
        int pid_1 = fork();
        if (pid_1 < 0) {
            perror("fork");
        }

        if(pid_1 == 0) {
            printf("Child process PID: %d\n", getpid());
        }

        else {
            printf("Parent process PID: %d\n", getpid());
        }

} 
