class MinStack {
public:
    stack<int>numS;
    stack<int>minS;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        numS.push(val);
        if (minS.empty()) {
            minS.push(val);
        } else {
            if (minS.top() > val)
                minS.push(val);
            else
                minS.push(minS.top());
        }
    }
    
    void pop() {
        minS.pop();
        numS.pop();
    }
    
    int top() {
        return numS.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
