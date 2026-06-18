class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int start = 0;
        int end = start+k-1;
        while(start < nums.size() && end < nums.size()) {
            int maxi = INT_MIN;
            for(int i = start; i <= end; i++) {
                maxi = max(nums[i],maxi);
            }
            ans.push_back(maxi);
            start++;
            end++;
        }
        return ans;
    }
};
