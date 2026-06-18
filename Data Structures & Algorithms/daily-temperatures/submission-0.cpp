class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        if(temp.size() == 1) return {0};
        vector<int>result;
        for(int i = 0; i < temp.size(); i++) {
            int count = 0;
            bool check = false;
            for(int j = i+1; j < temp.size(); j++) {
                if(temp[i] < temp[j]) {
                    result.push_back(j-i);
                    check = true;
                    break;
                }
            }
            if(!check) result.push_back(0);
        }
        return result;
    }
};
