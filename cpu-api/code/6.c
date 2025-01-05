#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // now exec "ls"...
        // char *myargs[2];
        // myargs[0] = strdup("/bin/ls");
        // myargs[1] = NULL;
        // mark end of array
        //printf("%d\n", execvp(myargs[0], myargs)); 
        printf("%d\n", execl("/bin/ls", "ls", NULL)); 
        int rc_wait = wait(NULL);
        printf("goodbye from child %d\n", rc_wait);
        
    }
    else
    {
        // parent goes down this path (main)
        int rc_wait = waitpid(rc, NULL, 0);
        printf("goodbye %d\n", rc_wait);
    }
    return 0;

}