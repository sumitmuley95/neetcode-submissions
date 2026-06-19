class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        int mini = *min_element(nums.begin(),nums.end());
        return mini;
    }
};
