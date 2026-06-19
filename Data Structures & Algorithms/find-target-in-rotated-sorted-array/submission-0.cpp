class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums[0] < nums[nums.size()-1]) return binarySearch(nums,target,0,nums.size()-1);
        int start = 0;
        int end = nums.size()-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[start] <= nums[mid]) {
                if(target >= nums[start] && target <= nums[mid]) return binarySearch(nums,target,start,mid);
                else start = mid+1;
            } else if(nums[mid] <= nums[end]) {
                if(target >= nums[mid] && target <= nums[end]) return binarySearch(nums,target,mid,end);
                else end = mid-1;
            }
        }
        return -1;
    }
};
