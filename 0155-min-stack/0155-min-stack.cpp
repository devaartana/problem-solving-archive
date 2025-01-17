class MinStack {
public:
    std::stack<int> st, stmin;
    int minval = INT_MAX;
    MinStack() {}

    void push(int val) {
        st.push(val);
        minval = std::min(val, minval);
        stmin.push(minval);
    }

    void pop() {
        st.pop();
        stmin.pop();
        minval = stmin.empty() ? INT_MAX : stmin.top(); 
    }

    int top() { return st.top(); }

    int getMin() { return stmin.top(); }
};
