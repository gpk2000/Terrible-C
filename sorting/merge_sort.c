#include "../helper/checks.h"
#include "../helper/prints.h"
#include <assert.h>

void merge_sort(int*, int, int);
void merge(int*, int, int, int);

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N);
    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    merge_sort(nums, 0, N - 1);
    assert(sort_check(nums, N));
    print_array(nums, N);
    return 0;
}

void merge_sort(int* nums, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    } else return;
}

void merge(int* nums, int start, int mid, int end) {
    // merges two sub-arrays of nums
    int aux[end - start + 5];
    int ptr_left = start, ptr_right = mid + 1;
    for (int k = start; k <= end; k++) {
        if (ptr_left == mid + 1) {
            aux[k] = nums[ptr_right++];
        } else if (ptr_right == end + 1) {
            aux[k] = nums[ptr_left++];
        } else if (nums[ptr_left] < nums[ptr_right]) {
            aux[k] = nums[ptr_left++];
        } else
            aux[k] = nums[ptr_right++];
    }
    for (int k = start; k <= end; k++)
        nums[k] = aux[k];
}
