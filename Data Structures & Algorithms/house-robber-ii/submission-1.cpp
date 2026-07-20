class Solution {
public:
    int solve(vector<int>&nums, int i, int start, int end, vector<int>& dp) {
        //base case
        if(i > end) return 0;
        if(dp[i] != -1) return dp[i];
        //ek case mera baki recursion
        int inc = nums[i]+solve(nums,i+2,start,end,dp);
        int exc = solve(nums,i+1,start,end,dp);
        return dp[i] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size()+1,-1);
        if(nums.size() == 1) return nums[0];
        int start = 0;
        int end = nums.size()-2;
        int sol1 = solve(nums,0,start,end,dp1);
        
        vector<int>dp2(nums.size()+1,-1);
        start = 1;
        end = nums.size()-1;
        int sol2 = solve(nums,1,start,end,dp2);
        return max(sol1,sol2);
    }
};
