class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length <= 0)
            return 0;
        int len = nums.length;
        int returnNum = 1;
        for(int i = 1; i < nums.length; ++i) {
            if(nums[i] == nums[returnNum - 1]) {
                continue;
            }
            else {
                nums[returnNum ++] = nums[i];
            }
        }
        return returnNum;
    }
}
