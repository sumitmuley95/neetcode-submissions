class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int finalMax = 0;
        for(int i = 0; i < heights.size(); i++) {
            int maxi = INT_MIN;
            int miniBar = heights[i];
            for(int j = i; j < heights.size(); j++) {
                miniBar = min(miniBar,heights[j]);
                int area = miniBar * (j-i+1);
                maxi = max(maxi,area);
            }
            finalMax = max(finalMax,maxi);
        }
        return finalMax;
    }
};
