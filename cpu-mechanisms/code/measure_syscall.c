/*
In this homework, you’ll measure the costs of a system call and context
switch. Measuring the cost of a system call is relatively easy. For example,
you could repeatedly call a simple system call (e.g., performing a 0-byte
read), and time how long it takes; dividing the time by the number of
iterations gives you an estimate of the cost of a system call.
One thing you’ll have to take into account is the precision and accu-
racy of your timer. A typical timer that you can use is gettimeofday();
read the man page for details. What you’ll see there is that gettimeofday()
returns the time in microseconds since 1970; however, this does not mean
that the timer is precise to the microsecond. Measure back-to-back calls
to gettimeofday() to learn something about how precise the timer re-
ally is; this will tell you how many iterations of your null system-call
test you’ll have to run in order to get a good measurement result. If
gettimeofday() is not precise enough for you, you might look into
using the rdtsc instruction available on x86 machines.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>

#define NUM_ITERATIONS 10000000


int main() 
{       
    struct timeval tvBefore, tvAfter;
    gettimeofday(&tvBefore, NULL);
    long int tBefore = tvBefore.tv_sec*1000000L+tvBefore.tv_usec;
    for (ssize_t i=0;i<NUM_ITERATIONS;++i){
        read(0, NULL, 0);
    }
    gettimeofday(&tvAfter, NULL);
    long int tAfter = tvAfter.tv_sec*1000000L+tvAfter.tv_usec;
    printf("%ld\n", tAfter-tBefore);
    printf("%lf\n", ((double)tAfter-tBefore) / NUM_ITERATIONS);
    return 0;
}