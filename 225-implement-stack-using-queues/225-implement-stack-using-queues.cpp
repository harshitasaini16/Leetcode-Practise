class MyStack {
public:
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        int x=q1.size();
        while(x>1){
            q1.push(q1.front());
            q1.pop();
            x--;
        }
        int y=q1.front();
        q1.pop();
        return y;
    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }
        int x=q1.size();
        while(x>1){
            q1.push(q1.front());
            q1.pop();
            x--;
        }
        int y=q1.front();
        q1.pop();
        q1.push(y);
        return y;
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */