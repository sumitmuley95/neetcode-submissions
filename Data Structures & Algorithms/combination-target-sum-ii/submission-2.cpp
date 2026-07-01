class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums, int target, int i, vector<int>& ans) {
        //base case 
        if(target == 0) {
            result.push_back(ans);
            return;
        }
        for(int it = i; it < nums.size(); it++) {
            if(nums[it] > target) break;
            if(it > i && nums[it] == nums[it-1]) continue;
            ans.push_back(nums[it]);
            solve(nums,target-nums[it],it+1,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>ans;
        solve(candidates,target,0,ans);
        return result;
    }
};
