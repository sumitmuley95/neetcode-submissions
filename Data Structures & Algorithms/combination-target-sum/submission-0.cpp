class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums, int target, int i, vector<int>& ans) {
        //base case
        if(target == 0) {
            result.push_back(ans);
            return;
        }
        if(i == nums.size() || target < 0) {
            return;
        }
        ans.push_back(nums[i]);
        //recursion 
        solve(nums,target-nums[i],i,ans);
        ans.pop_back();
        solve(nums,target,i+1,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ans;
        solve(nums,target,0,ans);
        return result;
    }
};