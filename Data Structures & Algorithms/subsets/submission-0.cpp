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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        solve(nums,ans,0);
        return result;
    }
};
