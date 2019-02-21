class MyQueue {
private:
     stack<int>  spush;
     stack<int> spop;
public:
    /** Initialize your data structure here. */
    MyQueue() {
       
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        spush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	if (spop.empty()){
        	while (!spush.empty()) {
				spop.push(spush.top());
				spush.pop();
        	}
     	}
        int res = spop.top();
		spop.pop();
		return res;
    }
    
    /** Get the front element. */
    int peek() {
    	if (spop.empty()){
      		while (!spush.empty()) {
				spop.push(spush.top());
				spush.pop();
      		}  
    	}
    	return spop.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return spush.empty()&&spop.empty();
    }
};
