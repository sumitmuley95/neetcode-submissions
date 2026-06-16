class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it : nums) {
            mpp[it]++;
        }

        int finalCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            int num = nums[i];
            while(mpp[num]) {
                count++;
                num = num+1;
            }
            finalCount = max(finalCount,count);
        }

        return finalCount;
    }
};
