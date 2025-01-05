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
        printf("child (pid:%d) x=%d\n", (int)getpid(), x);
        x = 20;
        printf("child (pid:%d) x=%d\n", (int)getpid(), x);
    }
    else
    {
        // parent goes down this path
        printf("parent (pid:%d) x=%d\n", (int)getpid(), x);
        x = 25;
        printf("parent (pid:%d) x=%d\n", (int)getpid(), x);
    }
    return 0;
}

/*
hello from parent (pid:18759) x=100
parent (pid:18759) x=100
parent (pid:18759) x=25
child (pid:18760) x=100
child (pid:18760) x=20
*/