class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for(auto pile : piles) {
            totalHours += (pile + k - 1)/k;
            if(totalHours > h) return false;
        }
        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(),piles.end());

        int low = 1;
        int high = maxPile;
        int result = maxPile;

        while(low <= high) {
            int mid = (low+high)/2;

            if(canEatAll(piles,h,mid)) {
                result = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return result;
    }
};
