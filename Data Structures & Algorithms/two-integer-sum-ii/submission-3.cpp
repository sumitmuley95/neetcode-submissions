class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i <= j) {
            int ans = nums[i]+nums[j];
            if(ans == target) return {i+1,j+1};
            if(ans > target) j--;
            else if(ans < target) i++;
        }
        return {};
    }
};
