#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    int single = 0;
    for (int i = 0; i < numsSize; i++) {
        single ^= nums[i];
    }
    return single;
}

int main() {
    int nums[] = {4,1,2,1,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = singleNumber(nums, numsSize);
    printf("%d", result);
    return 0;
}
