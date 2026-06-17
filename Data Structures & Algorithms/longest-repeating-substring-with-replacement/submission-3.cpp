class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxLength = 0;
        unordered_map<char,int>mpp;
        int highestFreq = 0;
        while(i < s.length() && j < s.length()) {
            mpp[s[j]]++;
            for(auto it : mpp) {
                highestFreq = max(highestFreq,it.second);
            }
            if(j-i-highestFreq+1 <= k) {
                //valid
                maxLength = max(maxLength,j-i+1);
            } else {
                mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return maxLength;
    }
};
