class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";

        vector<int>tCounts(128,0);
        for(auto i : t) {
            tCounts[i]++;
        }

        vector<int>sCounts(128,0);
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        int fullfilled = 0;
        int required = t.length();

        for(int right = 0; right < s.length(); right++) {
            char rightChar = s[right];
            sCounts[rightChar]++;

            if(tCounts[rightChar] > 0 && sCounts[rightChar] <= tCounts[rightChar]) fullfilled++;

            while(fullfilled == required) {
                if(right-left+1 < minLen) {
                    minLen = right-left+1;
                    minStart = left;
                }

                char leftChar = s[left];
                sCounts[leftChar]--;
                if(tCounts[leftChar] > 0 && sCounts[leftChar] < tCounts[leftChar]) fullfilled--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
