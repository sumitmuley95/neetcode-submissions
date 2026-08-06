class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int index = 0;
        while(index != nums.size()) {
            for(int i = index+1; i < nums.size();) {
                if(nums[index] == nums[i]) return true;
                i++;
            }
            index++;
        }
        return false;
    }
};