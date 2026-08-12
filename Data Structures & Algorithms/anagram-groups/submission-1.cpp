class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            string sortedWords = word;
            sort(sortedWords.begin(),sortedWords.end());
            groups[sortedWords].push_back(word);
        }
        vector<vector<string>> result;
        for(auto group : groups) {
            result.push_back(group.second);
        }
        return result; 
    }
};
