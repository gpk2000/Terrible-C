#include <assert.h>
#include "../helper/prints.h"
#include "../helper/checks.h"

void bubble_sort(int*, int);
void swap(int*, int*);

int main(int argc, char** argv) {
    int N;
    scanf("%d", &N); // get size as user inp
    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    bubble_sort(nums, N);
    assert(sort_check(nums, N));
    print_array(nums, N);
}

void bubble_sort(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
}

void swap(int* a, int* b) {
    // swap i'th and j'th elements
    int temp = *a;
    *a = *b;
    *b = temp;
}
