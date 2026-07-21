class Solution {
public:
    int count(string& s, int i, int j) {
        int count = 0;
        //ek case main solve karuga baki recursion
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int i = 0; i < s.length(); i++) {
            totalCount += count(s,i,i);
            totalCount += count(s,i,i+1);
        }
        return totalCount;
    }
};
