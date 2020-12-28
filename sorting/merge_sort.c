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
    merge_sort(nums, 0, N);
    assert(sort_check(nums, N));
    print_array(nums, N);
    return 0;
}

void merge_sort(int* nums, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid, end);
        merge(nums, start, mid, end);
    } else return;
}

void merge(int* nums, int start, int mid, int end) {
    // merges two sub-arrays of nums
    int temp_size = end - start;
    int temp[temp_size];
    int i = start, j = mid + 1, k = 0;
    while (i < mid && j < end) {
        if (nums[i] > nums[j])
            temp[k++] = nums[j++];
        else
            temp[k++] = nums[i++];
    }
    while (i < mid) temp[k++] = temp[i++];
    while (j < end) temp[k++] = temp[j++];
    for (int i = start; i < end; i++) nums[i] = temp[i];
}
