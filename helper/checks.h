#include <stdbool.h>

bool sort_check(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}
