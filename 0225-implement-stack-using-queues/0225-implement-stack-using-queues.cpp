class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int topele;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        topele = x;
    }
    
    int pop() {
        while(q1.size() != 1){
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            topele = q2.front();
            q2.pop();
        }
        return temp;
    }
    
    int top() {
        return topele;
    }
    
    bool empty() {
        if(!q1.empty()){
            return false;
        }
        return true;
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