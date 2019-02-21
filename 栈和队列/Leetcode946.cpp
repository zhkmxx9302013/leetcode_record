class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int>s;
        int count=0;
        for(int i=0;i<pushed.size();i++){
                s.push(pushed[i]);
            while(!s.empty()&&s.top()==popped[count]){
                s.pop();
                count++;
            }
        }
        if(!s.empty())
            return false;
        else
            return true;
    }
};
