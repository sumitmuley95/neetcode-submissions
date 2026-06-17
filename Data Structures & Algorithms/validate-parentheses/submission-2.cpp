class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int i = 0;
        while(i < s.length()) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(s[i] == ')') {
                    if(!st.empty() && st.top() == '(') {
                        st.pop();
                    } else return false;
                } else if(s[i] == ']') {
                    if(!st.empty() && st.top() == '[') {
                        st.pop();
                    } else return false;
                } else if(s[i] == '}') {
                    if(!st.empty() && st.top() == '{') {
                        st.pop();
                    } else return false;
                }
            }
            i++;
        }
        return st.empty();
    }
};
