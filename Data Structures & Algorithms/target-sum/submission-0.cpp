class Solution {
public:
    int count = 0;
    void solve(vector<int>& nums, int target, int i, int currSum) {
        //base case
        if(i == nums.size()) {
            if(currSum == target) {
                count++;
            }
            return;
        }
        //ek case main solve karuga
        solve(nums,target,i+1,currSum+nums[i]);
        solve(nums,target,i+1,currSum-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,target,0,0);
        return count;
    }
};
