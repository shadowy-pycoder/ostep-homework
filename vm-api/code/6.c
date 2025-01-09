#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int main(){

    int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    for (int i=0;i<ARRAY_SIZE;++i){
        array[i] = i;
    }
    free(array);
    printf("%d\n", array[0]);
    return 0;
}

/*
==192613== Invalid read of size 4
==192613==    at 0x1091B3: main (6.c:10)
==192613==  Address 0x4a9e040 is 0 bytes inside a block of size 400 free'd
==192613==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==192613==    by 0x1091AE: main (6.c:9)
==192613==  Block was alloc'd at
==192613==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==192613==    by 0x10919E: main (6.c:8)
==192613== 
0
==192613== 
==192613== HEAP SUMMARY:
==192613==     in use at exit: 0 bytes in 0 blocks
==192613==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==192613== 
==192613== All heap blocks were freed -- no leaks are possible
==192613== 
==192613== For lists of detected and suppressed errors, rerun with: -s
==192613== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/