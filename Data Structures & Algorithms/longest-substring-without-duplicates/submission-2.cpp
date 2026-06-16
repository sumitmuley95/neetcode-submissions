class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        int maxCount = 0;
        for(int i = 0; i < s.length(); i++) {
            int count = 0;
            unordered_map<char,int> mpp;
            for(int j = i; j < s.length(); j++) {
                if(!mpp[s[j]]) {
                    mpp[s[j]]++;
                    count++;
                } else {
                    break;
                }
                maxCount = max(count,maxCount);
            }
        }
        return maxCount;
    }
};
