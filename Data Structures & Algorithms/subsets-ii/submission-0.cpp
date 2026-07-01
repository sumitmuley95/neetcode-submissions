class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums,vector<int>& ans, int i) {
        //base case 
        if(i == nums.size()) {
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        solve(nums,ans,i+1);
        ans.pop_back();
        solve(nums,ans,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        solve(nums,ans,0);
        for(auto i : result) {
            st.insert(i);
        }
        vector<vector<int>>finalAns;
        for(auto i : st) finalAns.push_back(i);
        return finalAns;
    }
};
