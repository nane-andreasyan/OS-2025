#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
        pid_t pid_1;
        pid_t pid_2;
        pid_t pid_3;

        pid_1 = fork();
        if (pid_1 == -1)
            perror ("fork1");
 
        pid_2 = fork();
        if (pid_2 == -1)
            perror ("fork2");
 
        pid_3 = fork();
        if (pid_3 == -1)
            perror ("fork3");
            
        sleep(10);
       
        return 0; 

} 