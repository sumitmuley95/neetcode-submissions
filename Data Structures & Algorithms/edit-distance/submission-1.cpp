class Solution {
public:
    int solve(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        //base case
        if(j > word2.length() || i > word1.length()) return 0;
        if(j == word2.length() && i != word1.length()) return word1.length()-i;
        if(i == word1.length() && j != word2.length()) return word2.length()-j;
        if(j == word2.length() && i == word1.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //ek case main baki recursion
        if(word1[i] == word2[j]) {
            return dp[i][j] = solve(word1,word2,i+1,j+1,dp);
        } return dp[i][j] = 1 + min(solve(word1,word2,i+1,j,dp),min(solve(word1,word2,i,j+1,dp),solve(word1,word2,i+1,j+1,dp)));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};
