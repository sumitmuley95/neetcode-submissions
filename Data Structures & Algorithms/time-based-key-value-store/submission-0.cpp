class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end()) {
            return "";
        }
        auto& vec = mpp[key];

        auto it = upper_bound(vec.begin(), vec.end(), make_pair(timestamp, string("")), 
            [](const pair<int, string>& a, const pair<int, string>& b) {
                return a.first < b.first;
            });
        if (it == vec.begin()) {
            return "";
        }
        
        return prev(it)->second;
    }
};
