class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp) {
        //base case
        int k = i+j;
        if(k == s3.length()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        //recursion
        return dp[i][j] = (i < s1.length() && s1[i] == s3[k] && solve(s1,s2,s3,i+1,j,dp))
            ||  (j < s2.length() && s2[j] == s3[k] && solve(s1,s2,s3,i,j+1,dp));
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};
