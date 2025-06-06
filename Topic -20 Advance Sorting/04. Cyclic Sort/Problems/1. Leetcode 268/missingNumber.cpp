/*
    ## Missing Number  [Leetcode 268]


    class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // cyclic sort
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i];
            if(correctIdx==i || nums[i]==n)i++;
            else swap(nums[i],nums[correctIdx]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};
*/