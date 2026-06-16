class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int finalAns = 0;
        while(i < j) {
            int prefixSum = (j-i) * (min(heights[i],heights[j]));
            if(heights[i] < heights[j]) i++;
            else j--;

            finalAns = max(prefixSum,finalAns);
        }

        return finalAns;
    }
};
