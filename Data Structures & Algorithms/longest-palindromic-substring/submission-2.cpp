class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            int left = i;
            int right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
                if(maxLen < right-left-1) {
                    maxLen = right-left-1;
                    start = left+1;
                }
            }

            left = i;
            right = i+1;
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
                if(maxLen < right-left-1) {
                    maxLen = right-left-1;
                    start = left+1;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
