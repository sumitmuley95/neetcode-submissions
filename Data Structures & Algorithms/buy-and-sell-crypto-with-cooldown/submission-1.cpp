class Solution {
public:
    int solve(vector<int>& prices, int i, bool canBuy, vector<vector<int>>& dp) {
        //base case
        if(i >= prices.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        //ek case main baki recursion
        if(canBuy) {
            return dp[i][canBuy] = max(-prices[i]+solve(prices,i+1,false,dp), solve(prices,i+1,true,dp));
        } else {
            return dp[i][canBuy] = max(+prices[i]+solve(prices,i+2,true,dp), solve(prices,i+1,false,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,true,dp);
    }
};
