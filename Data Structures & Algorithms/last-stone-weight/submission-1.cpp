class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while(!pq.empty()) {
            int elem1 = pq.top();
            pq.pop();
            if(pq.empty()) return elem1;
            int elem2 = pq.top();
            pq.pop();

            if(elem1 > elem2) {
                elem1 = elem1-elem2;
                pq.push(elem1);
            } else if(elem1 < elem2) {
                elem2 = elem2-elem1;
                pq.push(elem2);
            }
        }
        return 0;
    }
};
