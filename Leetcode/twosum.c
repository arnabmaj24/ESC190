/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int main(){

    int nums[] = {2,7,11,15};

    int x[] = twoSum(nums, 4, 9, 2);



    return 0;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int *array = (int *)malloc(2*sizeof(int));
    int i,j;

    for (i=0; i<numsSize;i++){
        for (j=0;j<numsSize;j++){
            if (nums[i]+nums[j] == target);
            array[0] =i;
            array[1] = j;
            
        }
    }
    
    return array;
    

}