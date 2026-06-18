class Solution {
public:
    bool binarySearch(vector<int>& row, int start, int end, int target) {
        while(start <= end) {
            int mid = (start+end)/2;
            if(target == row[mid]) return true;
            else if(target > row[mid]) start = mid+1;
            else end = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] <= target && matrix[i][cols-1] >= target) {
                if(binarySearch(matrix[i],0,cols-1,target)) return true;
            }
        }
        return false;
    }
};
