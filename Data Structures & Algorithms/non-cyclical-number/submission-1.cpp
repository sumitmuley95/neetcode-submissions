class Solution {
public:
    bool isHappy(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        vector<int>nums;

        while(true) {
            string num = to_string(n);
            int ans = 0;
            for(int i = 0; i < num.length(); i++) {
                int digit = (num[i]-'0');
                ans += digit*digit;
            }
            if(ans == 1) return true;
            else {
                auto it = find(nums.begin(),nums.end(),ans);
                if(it != nums.end()) return false;
                n = ans;
                nums.push_back(n);
            }
        }
        return true;
    }
};
