class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int a = s1.top();
            s2.push(a);
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            int a = s2.top();
            s1.push(a);
            s2.pop();
        }
    }
    
    int pop() {
        int a = s1.top();
        s1.pop();
        return a;
    }
    
    int peek() {
        int a = s1.top();
        return a;
    }
    
    bool empty() {
        // return s1.empty();
        if(!s1.empty()){
            return false;
        }
        return true;
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