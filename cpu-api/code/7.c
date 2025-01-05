#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <assert.h>


int main(int argc, char *argv[])
{
    printf("hello from parent (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child (new process)
    printf("child before closing stdout (pid:%d)\n", (int)getpid());
        assert (close(STDOUT_FILENO)==0);
        printf("child after closing stdout (pid:%d)\n", (int)getpid());
    }
    else
    {
        // parent goes down this path
        printf("parent (pid:%d)\n", (int)getpid());
    }
    return 0;
}

/*
hello from parent (pid:46466)
parent (pid:46466)
child before closing stdout (pid:46467)
*/