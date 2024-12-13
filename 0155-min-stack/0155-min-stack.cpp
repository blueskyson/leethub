class MinStack {
public:
    vector<pair<int, int>> stack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if (stack.empty()) {
            stack.push_back(pair<int, int>(val, val));
        } else {
            pair<int, int> p(val, 0);
            p.second = min(stack.back().second, val);
            stack.push_back(p);
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
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