#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    int x;
    x = 100;
    printf("hello from parent (pid:%d) x=%d\n", (int)getpid(), x);
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child (new process)
        printf("hello\n");
    }
    else
    {
        // parent goes down this path
        int rc_wait = wait(NULL);
        printf("goodbye %d\n", rc_wait);
    }
    return 0;
}