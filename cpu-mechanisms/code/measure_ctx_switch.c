/*
Measuring the cost of a context switch is a little trickier. The lmbench
benchmark does so by running two processes on a single CPU, and set-
ting up two U NIX pipes between them; a pipe is just one of many ways
processes in a U NIX system can communicate with one another. The first
process then issues a write to the first pipe, and waits for a read on the
second; upon seeing the first process waiting for something to read from
the second pipe, the OS puts the first process in the blocked state, and
switches to the other process, which reads from the first pipe and then
writes to the second. When the second process tries to read from the first
pipe again, it blocks, and thus the back-and-forth cycle of communication
continues. By measuring the cost of communicating like this repeatedly,
lmbench can make a good estimate of the cost of a context switch. You
can try to re-create something similar here, using pipes, or perhaps some
other communication mechanism such as U NIX sockets.
One difficulty in measuring context-switch cost arises in systems with
more than one CPU; what you need to do on such a system is ensure that
your context-switching processes are located on the same processor. For-
tunately, most operating systems have calls to bind a process to a partic-
ular processor; on Linux, for example, the sched setaffinity() call
is what you’re looking for. By ensuring both processes are on the same
processor, you are making sure to measure the cost of the OS stopping
one process and restoring another on the same CPU.
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sched.h>

#define NUM_ITERATIONS 10000000

int main()
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    printf("parent in pid: (%d)\n", (int)getpid());
    fflush(stdout);
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);

    int rc = fork();
    if (rc == 0)
    {
        if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) == -1)
        {
            exit(EXIT_FAILURE);
        }
        printf("entering child process at pid : (%d)\n", (int)getpid());
        for (ssize_t i = 0; i < NUM_ITERATIONS; ++i)
        {
            read(p1[0], NULL, 0);
            write(p2[1], NULL, 0);
        }
    }
    else
    {
        if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) == -1)
        {
            exit(EXIT_FAILURE);
        }
        struct timeval tvBefore, tvAfter;
        gettimeofday(&tvBefore, NULL);
        long int tBefore = tvBefore.tv_sec * 1000000L + tvBefore.tv_usec;
        printf("entering parent process at pid : (%d)\n", (int)getpid());
        for (ssize_t i = 0; i < NUM_ITERATIONS; ++i)
        {
            read(p1[1], NULL, 0);
            write(p2[0], NULL, 0);
        }
        gettimeofday(&tvAfter, NULL);
        long int tAfter = tvAfter.tv_sec * 1000000L + tvAfter.tv_usec;
        printf("%ld\n", tAfter - tBefore);
        printf("%lf\n", ((double)tAfter - tBefore) / NUM_ITERATIONS);
    }
    return 0;
}