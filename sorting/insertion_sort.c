#include "../helper/prints.h"
#include "../helper/checks.h"
#include <assert.h>

void insertion_sort(int*, int);

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N); // get the size as inp
    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    insertion_sort(nums, N);
    assert(sort_check(nums, N));
    print_array(nums, N);
    return 0;
}

void insertion_sort(int* nums, int size) {
    for (int i = size - 1; i >= 0; i--) {
        // place the current el in correct pos
        int key = nums[i];
        int j = i + 1;
        while (j < size && nums[j] <= key) {
            nums[j - 1] = nums[j];
            j++;
        }
        nums[j - 1] = key;
    }
}
