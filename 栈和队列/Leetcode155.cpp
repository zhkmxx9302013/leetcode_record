class MinStack {
  public:
      /** initialize your data structure here. */
      MinStack() {
          
      }
      
      void push(int x) {
          mainStack.push(x);
          if(subStack.empty() || x <= subStack.top()){
              subStack.push(x);
          }
      }
      
      void pop() {
          int tmp = mainStack.top();
          mainStack.pop();
          if(tmp == subStack.top()){
              subStack.pop();
          }
      }
      
      int top() {
          int res = mainStack.top();
          return res;
      }
      
      int getMin() {
          //if(subStack.empty()) return 0;
          return subStack.top();
      }
  
  private:
      stack<int> mainStack;
      stack<int> subStack;
  };
  
  /**
   * Your MinStack object will be instantiated and called as such:
   * MinStack obj = new MinStack();
   * obj.push(x);
   * obj.pop();
   * int param_3 = obj.top();
   * int param_4 = obj.getMin();
   */
