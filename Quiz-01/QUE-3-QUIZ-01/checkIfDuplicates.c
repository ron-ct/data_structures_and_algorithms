#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int nums[] = {1,2,3,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = containsDuplicate(nums, numsSize);
    printf("%s", result ? "true" : "false");
    return 0;
}
