class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);
        int maxFreq = 0;
        int left = 0;
        int result = 0;
        for(int right = 0; right < s.length(); right++) {
            v[s[right]-'A']++;
            maxFreq = max(maxFreq,v[s[right]-'A']);

            if((right-left+1) - maxFreq > k) {
                v[s[left]-'A']--;
                left++;
            }
            result = max(result,right-left+1);
        }
        return result;
    }
};
