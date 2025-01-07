#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Current Process ID = %d\n",getpid());

    if (argc != 2)
    {
        printf("Usage: app <MB>\n");
        exit(EXIT_FAILURE);
    }
    int num_mb = atoi(argv[1]) * 1000 * 1000;
    printf("%d\n", num_mb);
    int *array = (int*)malloc(num_mb * sizeof(int));;

    while (1)
    {
        printf(".");
        fflush(stdout);
        for (int i = 0; i < num_mb/(int)sizeof(int); i++)
        {
            array[i] = i;
        }
    }
    return 0;
}