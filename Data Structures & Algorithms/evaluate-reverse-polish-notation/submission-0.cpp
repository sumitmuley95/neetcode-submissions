class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                //operator
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                int ans = 0;
                if(tokens[i] == "+") {
                    ans = op1+op2;
                } else if(tokens[i] == "-") {
                    ans = op2-op1;
                } else if(tokens[i] == "*") {
                    ans = op1*op2;
                } else {
                    ans = op2/op1;
                }
                st.push(ans);
            } else {
                //operand
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
