class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        stack<int>st;
        while(i<pushed.size() && j<popped.size()){
            st.push(pushed[i]);
            while(!st.empty() && j<popped.size() && popped[j] == st.top()){
                    st.pop();
                    j++;
                }
                i++;  
        }
        
        if(st.empty()){
            return true;
        }
        return false;
    }
};