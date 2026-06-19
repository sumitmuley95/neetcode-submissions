class Solution {
public:
    int findMin(vector<int> &nums) {
        //nums is 0 times rotated and sorted
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        int dedicatedValue = INT_MAX;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end) {
            int mid = (start+end)/2;
            if(nums[mid] < dedicatedValue) {
                dedicatedValue = nums[mid];
            }
            if(nums[start] <= nums[mid]) {
                if(nums[mid] > nums[end]) {
                    start = mid+1;
                } else {
                    dedicatedValue = min(dedicatedValue,nums[start]);
                    break;
                }
            }
            else end = mid-1;
        }
        return dedicatedValue;
    }
};
