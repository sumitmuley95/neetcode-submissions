class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        
        int i = 0;
        while (i < nums.size()) {
            if (i + nums[i] >= nums.size() - 1) return true;
            if (nums[i] == 0) return false;
            
            int farthestLanding = i;
            int nextIndex = i;
            for (int it = i + 1; it <= i + nums[i]; it++) {
                if (it + nums[it] > farthestLanding) {
                    farthestLanding = it + nums[it];
                    nextIndex = it;
                }
            }
            i = nextIndex;
        }
        
        return false;
    }
};
