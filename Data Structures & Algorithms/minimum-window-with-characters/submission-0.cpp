class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        vector<int>tCounts(128,0);
        for(auto c : t) {
            tCounts[c]++;
        }

        vector<int>sCounts(128,0);

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        int required = t.length();
        int formed = 0;

        for(int i = 0; i < s.length(); i++) {
            char rightChar = s[i];
            sCounts[rightChar]++;

            if(tCounts[rightChar] > 0 && sCounts[rightChar] <= tCounts[rightChar]) {
                formed++;
            }

            while(formed == required) {
                if(i - left + 1 < minLen) {
                    minLen = i-left+1;
                    minStart = left;
                }
                char leftChar = s[left];
                sCounts[leftChar]--;

                if(tCounts[leftChar] > 0 && sCounts[leftChar] < tCounts[leftChar]) formed--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
