class Solution {
public:
    int solve(vector<int>& result, int i, int j, vector<vector<int>>& dp) {
        //base case
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //ek case main baki recursion
        int maxi = 0;
        for(int k = i; k <= j; k++) {
            int coins = result[i-1]*result[k]*result[j+1] + 
            solve(result,i,k-1,dp) + solve(result,k+1,j,dp);
            maxi = max(maxi,coins);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>result;
        result.push_back(1);
        for(auto i : nums) result.push_back(i);
        result.push_back(1);
        vector<vector<int>>dp(result.size(),vector<int>(result.size(),-1));
        return solve(result,1,nums.size(),dp);
    }
};
