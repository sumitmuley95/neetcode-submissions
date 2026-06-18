class MinStack {
public:
    vector<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        int mini = INT_MAX;
        for(int i = 0; i < st.size(); i++) {
            mini = min(mini,st[i]);
        }
        return mini;
    }
};
