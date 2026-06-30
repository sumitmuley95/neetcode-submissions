class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<
        pair<int, pair<int, int>>,              // 1. The Element Type
        vector<pair<int, pair<int, int>>>,      // 2. The Underlying Container
        greater<pair<int, pair<int, int>>>      // 3. The Comparator
    > pq;
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = (x*x)+(y*y);

            pq.push({dist,{x,y}});
        }

        vector<vector<int>> result;
        if(k > pq.size()) return result;
        while(!pq.empty() && k > 0) {
            auto topElem = pq.top();
            pq.pop();

            int x = topElem.second.first;
            int y = topElem.second.second;

            result.push_back({x,y});
            k--;
        }
        return result;
    }
};
