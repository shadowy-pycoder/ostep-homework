#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int main(){

    int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    array[100] = 0;
    free(array);
    return 0;
}

/*
==190207== Invalid write of size 4
==190207==    at 0x10918D: main (5.c:9)
==190207==  Address 0x4a9e1d0 is 0 bytes after a block of size 400 alloc'd
==190207==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==190207==    by 0x10917E: main (5.c:8)
==190207== 
==190207== 
==190207== HEAP SUMMARY:
==190207==     in use at exit: 0 bytes in 0 blocks
==190207==   total heap usage: 1 allocs, 1 frees, 400 bytes allocated
==190207== 
==190207== All heap blocks were freed -- no leaks are possible
==190207== 
==190207== For lists of detected and suppressed errors, rerun with: -s
==190207== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/