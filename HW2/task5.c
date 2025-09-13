#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <stdlib.h>


int main() 
{ 
        int pid_1 = fork();
        if (pid_1 < 0) {
            perror("fork");
        }

        if(pid_1 == 0) {
            execl("/usr/bin/grep", "grep", "main", "test.txt", NULL);
            //execl("/bin/sh", "/bin/sh", "-c", "grep main test.txt");
            perror("execl error");
            exit(1);
        }

        wait(NULL);
        printf("Parent process done\n");
} 