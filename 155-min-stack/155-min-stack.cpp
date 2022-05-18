class MinStack {
public:
    
    // using space
    stack<int> s;
    stack<int> ss;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty() || ss.top() >= val)
            ss.push(val);
    }
    
    void pop() {
        if(ss.top()==s.top())
            ss.pop();
        s.pop();
    }
    
    int top() {
        if(s.empty())
            return NULL;
        else
            return s.top();
    }
    
    int getMin() {
        if(ss.empty())
            return NULL;
        else
            return ss.top();
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