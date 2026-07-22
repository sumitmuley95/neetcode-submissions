class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, int sum) {
        //base case
        if(sum > amount || i == coins.size()) return INT_MAX;
        if(sum == amount) return 0;
        //ek case main solve karuga baki recursion
        int inc = solve(coins,amount,i,sum+coins[i]);
        if(inc != INT_MAX) inc = 1 + inc;
        int exc = solve(coins,amount,i+1,sum);
        return min(inc,exc);
    }
    int coinChange(vector<int>& coins, int amount) {
        int result = solve(coins,amount,0,0);
        if(result == INT_MAX) return -1;
        return result;
    }
};
