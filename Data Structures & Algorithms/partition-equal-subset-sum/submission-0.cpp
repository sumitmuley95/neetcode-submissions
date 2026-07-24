class Solution {
public:
    int solve(vector<int>& nums, int halfSum, int i) {
        //base case
        if(halfSum == 0) return true;
        if(i == nums.size() || halfSum < 0) return false;
        //ek case main solve karuga
        return solve(nums,halfSum-nums[i],i+1) || solve(nums,halfSum,i+1);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto i : nums) totalSum += i;
        if(totalSum % 2 != 0) return false;

        if(solve(nums,totalSum/2,0)) return true;
        return false;
    }
};
