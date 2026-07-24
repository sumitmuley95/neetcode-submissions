class Solution {
public:
    int solve(int amount, vector<int>& coins, int i, int val,vector<vector<int>>& dp) {
        //base case
        if(val == amount) return 1;
        if(val > amount || i == coins.size()) return 0;
        if(dp[i][val] != -1) return dp[i][val];
        //ek case main baki recursion
        return dp[i][val] = solve(amount,coins,i,val+coins[i],dp) + solve(amount,coins,i+1,val,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(amount,coins,0,0,dp);
    }
};
