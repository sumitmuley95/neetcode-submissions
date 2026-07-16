class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k) {
        int totalTime = 0;
        for(auto pile : piles) {
            totalTime += ((pile+k-1)/k);
            if(totalTime > h) return false;
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        sort(piles.begin(),piles.end());
        int end = piles[piles.size()-1];

        int result = end;

        while(start <= end) {
            int mid = (start+end)/2;
            if(canEatAll(piles,h,mid)) {
                result = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return result;
    }
};
