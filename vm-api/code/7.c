#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int main(){

    int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    for (int i=0;i<ARRAY_SIZE;++i){
        array[i] = i;
    }
    for (int i=0;i<ARRAY_SIZE;++i){
         printf("%d ", array[i]);
    }
    int *mid_ptr = array+(ARRAY_SIZE/2);
    printf("%d\n", *mid_ptr);
    free(mid_ptr);
    return 0;
}

/*
code/7.c: In function ‘main’:
code/7.c:17:5: warning: ‘free’ called on pointer ‘array’ with nonzero offset 200 [-Wfree-nonheap-object]
   17 |     free(mid_ptr);
      |     ^~~~~~~~~~~~~
code/7.c:8:24: note: returned from ‘malloc’
    8 |     int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));
*/