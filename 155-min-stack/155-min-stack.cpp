class MinStack {
public:
    stack<int>q;
    MinStack() {
        while(!q.empty()){
            q.pop();
        }
    }
    
    void push(int val) {
        if(q.empty()){
            q.push(val);
            q.push(val);
        }
        else{
            int x=min(val,q.top());
            q.push(val);
            q.push(x);
        }
    }
    
    void pop() {
        q.pop();
        q.pop();
    }
    
    int top() {
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        q.push(y);
        q.push(x);
        return y;
    }
    
    int getMin() {
        return q.top();
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