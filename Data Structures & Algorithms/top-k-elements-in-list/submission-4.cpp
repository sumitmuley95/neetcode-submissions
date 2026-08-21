class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i : nums) {
            m[i]++;
        }

        vector<pair<int,int>> freq(m.begin(), m.end());

        // sort by frequency descending
        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;


        
    }
};
