#include <assert.h>
#include "../helper/prints.h"
#include "../helper/checks.h"

void bubble_sort(int*, int);
void swap(int*, int, int);

int main(int argc, char** argv) {
    int N;
    scanf("%d", &N); // get size as user inp
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, N);
    assert(sort_check(a, N));
    print_array(a, N);
}

void bubble_sort(int* arr_ptr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr_ptr[j] > arr_ptr[j + 1]) {
                swap(arr_ptr, j, j + 1);
            }
        }
    }
}

void swap(int* arr_ptr, int i, int j) {
    // swap i'th and j'th elements
    int temp = arr_ptr[i];
    arr_ptr[i] = arr_ptr[j];
    arr_ptr[j] = temp;
}
