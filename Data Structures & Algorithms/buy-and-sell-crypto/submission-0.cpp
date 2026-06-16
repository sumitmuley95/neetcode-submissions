class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>lowest;
        vector<int>highest;

        int low = prices[0];
        for(int i = 0; i < prices.size(); i++) {
            low = min(low,prices[i]);
            lowest.push_back(low);
        }

        int high = prices[prices.size()-1];
        for(int j = prices.size()-1; j >= 0; j--) {
            high = max(high,prices[j]);
            highest.push_back(high);
        }

        reverse(highest.begin(),highest.end());

        int profit = 0;

        for(int i = 0; i < prices.size(); i++) {
            profit = max(profit, highest[i]-lowest[i]);
        }

        return profit;
    }
};
