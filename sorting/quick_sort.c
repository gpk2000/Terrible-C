#include "../helper/checks.h"
#include "../helper/prints.h"
#include <stdlib.h>
#include <assert.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N); // get the len as user inp
    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    quick_sort(nums, 0, N - 1);
    assert(sort_check(nums, N));
    print_array(nums, N);
    return 0;
}

void quick_sort(int* nums, int start, int end) {
    if (start < end) {
        int pivotIdx = partition(nums, start, end);
        quick_sort(nums, start, pivotIdx - 1);
        quick_sort(nums, pivotIdx + 1, end);
    }
}

int partition(int* nums, int start, int end) {
    // Pivot is nums[end]
    swap(&nums[start + (rand() % (end - start + 1))], &nums[end]);
    int i = start - 1;
    for (int j = start; j <= end; j++) {
        if (nums[j] <= nums[end]) {
            swap(&nums[++i], &nums[j]);
        }
    }
    return i;
}

void swap(int* a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
