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
    int fd = open("./2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    assert (fd > 0);
    char greetings[] = "Hello World!\n";
    size_t n = sizeof(greetings) / sizeof(greetings[0]);
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
        printf("child (pid:%d) bytes written=%ld\n", (int)getpid(), write(fd, greetings, n));
    }
    else
    {
        // parent goes down this path
        printf("parent (pid:%d) bytes written=%ld\n", (int)getpid(), write(fd, greetings, n));
    }
    assert (close(fd) == 0);
    return 0;
}
