class Solution {
public:
    vector<string>result;
    void solve(int n, int open, int close, string s) {
        if(open > n || close > n) return;
        if(close > open) return;
        if(s.length() == 2*n) {
            result.push_back(s);
            return;
        }

        solve(n,open+1,close,s+'('); //do we need include exclude pattern here I guess
        solve(n,open,close+1,s+')');
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return result;
    }
};
