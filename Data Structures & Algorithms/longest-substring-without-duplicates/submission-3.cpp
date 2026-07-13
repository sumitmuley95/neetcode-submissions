class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length() == 1) return s.length();

        int n = s.length();
        int i = 0, j = 0;
        int result = INT_MIN;
        unordered_map<char,int>mpp;
        while(j < n) {
            mpp[s[j]]++;
            while(mpp[s[j]] > 1) {
                mpp[s[i]]--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;
    }
};
