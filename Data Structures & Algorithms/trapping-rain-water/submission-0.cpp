class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefix;
        vector<int>suffix;

        int greatestPrefix = height[0];
        for(int i = 0; i < height.size(); i++) {
            greatestPrefix = max(greatestPrefix,height[i]);
            prefix.push_back(greatestPrefix);
        }

        int greatestSuffix = height[height.size()-1];
        for(int j = height.size()-1; j >= 0; j--) {
            greatestSuffix = max(greatestSuffix,height[j]);
            suffix.push_back(greatestSuffix);
        }
        reverse(suffix.begin(),suffix.end());

        int totalWaterTrapped = 0;
        for(int i = 0 ; i < height.size(); i++) {
            int currWater = min(prefix[i],suffix[i]) - height[i];
            totalWaterTrapped += currWater;
        }


        return totalWaterTrapped;
    }
};
