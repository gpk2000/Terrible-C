#include <stdio.h>

void print_array(int* arr_ptr, int size) {
    for (int i = 0; i < size; i++) {
        if (i > 0)
            printf(" %d", arr_ptr[i]);
        else
            printf("%d", arr_ptr[i]);
    }
    printf("\n");
}
