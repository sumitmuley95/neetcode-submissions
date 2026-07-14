class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int>s1Counts(26,0);
        vector<int>s2Counts(26,0);
    
        for(int i = 0; i < s1.length(); i++) {
            s1Counts[s1[i]-'a']++;
            s2Counts[s2[i]-'a']++;
        }

        if(s1Counts == s2Counts) return true;

        for(int i = s1.length(); i < s2.length(); i++) {
            s2Counts[s2[i] - 'a']++;
            s2Counts[s2[i - s1.length()] - 'a']--;

            if(s1Counts == s2Counts) return true;
        }

        return false;
    }
};
