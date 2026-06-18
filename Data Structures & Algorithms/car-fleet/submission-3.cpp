class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 0) return 0;
        vector<pair<int,int>>cars(position.size());
        for(int i = 0; i < position.size(); i++) {
            cars[i] = {position[i],speed[i]};
        }
        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        int fleet = 0;
        double maxTimeSeen = 0.0;

        for(int i = 0; i < position.size(); i++) {
            double timeRequired = (double)(target - cars[i].first)/cars[i].second;
            if(timeRequired > maxTimeSeen) {
                fleet++;
                maxTimeSeen = timeRequired;
            }
        }

        return fleet;
    }
};
