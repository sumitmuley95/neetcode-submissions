class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string& s, int start, vector<string>& current_path, vector<vector<string>>& result) {
        //base case 
        if (start == s.length()) {
            result.push_back(current_path);
            return;
        }

        //recursion 
        for (int end = start; end < s.length(); ++end) {
        if (isPalindrome(s, start, end)) {
            current_path.push_back(s.substr(start, end - start + 1));
            solve(s, end + 1, current_path, result);
            current_path.pop_back();
        }
    }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>ans;
        solve(s,0,ans,result);
        return result;
    }
};
