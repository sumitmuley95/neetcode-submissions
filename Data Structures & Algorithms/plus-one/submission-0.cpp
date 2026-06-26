class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1] <= 8) {
            digits[digits.size()-1] += 1;
            return digits;
        }
        
        string num = "";
        for(int i = 0; i < digits.size(); i++) {
            num += to_string(digits[i]);
        }

        int number = stoi(num);
        int ans = number+1;
        string addedNum = to_string(ans);

        vector<int>result;
        for(int i = 0; i < addedNum.length(); i++) {
            result.push_back(addedNum[i]-'0');
        }
        return result;
    }
};
