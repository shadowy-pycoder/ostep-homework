#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000

int main(){

    char *array = (char*)malloc(ARRAY_SIZE * sizeof(char));
    for (int i=0;i<ARRAY_SIZE;++i){
        array[i] = 'a';
    }
    for (int i=0;i<ARRAY_SIZE;++i){
        printf("%c", array[i]);
    }
    return 0;
}

/*
==104669== HEAP SUMMARY:
==104669==     in use at exit: 10,000 bytes in 1 blocks
==104669==   total heap usage: 2 allocs, 1 frees, 11,024 bytes allocated
==104669== 
==104669== 10,000 bytes in 1 blocks are definitely lost in loss record 1 of 1
==104669==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==104669==    by 0x10917E: main (4.c:8)
==104669== 
==104669== LEAK SUMMARY:
==104669==    definitely lost: 10,000 bytes in 1 blocks
==104669==    indirectly lost: 0 bytes in 0 blocks
==104669==      possibly lost: 0 bytes in 0 blocks
==104669==    still reachable: 0 bytes in 0 blocks
==104669==         suppressed: 0 bytes in 0 blocks
==104669== 
==104669== For lists of detected and suppressed errors, rerun with: -s*/