#include "../helper/prints.h"
#include "../helper/checks.h"
#include <assert.h>

void selection_sort(int*, int);
void swap(int*, int*);
int find_pos(int*, int, int);

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N); // get size as user inp
    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    selection_sort(nums, N);
    assert(sort_check(nums, N));
    print_array(nums, N);
    return 0;
}

void selection_sort(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        // get the position of the element that should be here
        int pos = find_pos(nums, i, size);
        swap(&nums[i], &nums[pos]);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_pos(int* nums, int start, int size) {
    // finds the minimum element from nums[start:end]
    int pos_assume = start;
    int el_assume = nums[start];
    for (int i = start + 1; i < size; i++) {
        if (nums[i] < el_assume) { // got a better one
            el_assume = nums[i];
            pos_assume = i;
        }
    }
    return pos_assume;
}
