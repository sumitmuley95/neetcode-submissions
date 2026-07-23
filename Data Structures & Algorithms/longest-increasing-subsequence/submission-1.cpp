class Solution {
public:
    int solve(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp) {
        //base case
        if(curr == nums.size()) return 0;
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];
        //ek case main solve karuga
        int include = 0;
        if(prev == -1 || nums[prev] < nums[curr]) {
            include = 1 + solve(nums,curr,curr+1,dp);
        }
        int exclude = 0 + solve(nums,prev,curr+1,dp);
        return dp[prev+1][curr] = max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,-1,0,dp);
    }
};
