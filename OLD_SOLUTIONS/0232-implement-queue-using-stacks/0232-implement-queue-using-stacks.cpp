class MyQueue {
public:
stack<int> i,o;
    MyQueue() {
        
    }
    
    void push(int x) {
        i.push(x);
    }
    
    int pop() {
        if(o.empty()){
            while(!i.empty()){
                o.push(i.top());
                i.pop();
            }
        }
        int x = o.top();
        o.pop();
        return x;
    }
    
    int peek() {
        if(o.empty()){
            while(!i.empty()){
                o.push(i.top());
                i.pop();
            }
        }
        int x = o.top();
        return x;
    }
    
    bool empty() {
        return ((i.size()+o.size() )== 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */