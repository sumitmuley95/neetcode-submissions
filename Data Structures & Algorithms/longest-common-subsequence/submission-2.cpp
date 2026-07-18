class Solution {
public:
    int solve(string &t1, string& t2, int i, int j,vector<vector<int>>& dp) {
        //base case
        if(i == t1.length() || j == t2.length()) return 0;
        //ek case mera baki recursion
        if(dp[i][j] != -1) return dp[i][j];
        if(t1[i] == t2[j]) return dp[i][j] = 1 + solve(t1,t2,i+1,j+1,dp);
        else {
            int t1Check = solve(t1,t2,i+1,j,dp);
            int t2Check = solve(t1,t2,i,j+1,dp);

            return dp[i][j] = max(t1Check,t2Check);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(text1,text2,0,0,dp);
    }
};
