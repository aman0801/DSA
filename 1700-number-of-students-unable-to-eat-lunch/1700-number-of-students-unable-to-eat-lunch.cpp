class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
            queue<int>q;
            stack<int>st;
            
            for(int i=0; i<students.size(); i++){
                    q.push(students[i]);
                    st.push(sandwiches[sandwiches.size()-i-1]);
            }
            int count=0;
            while(!q.empty() && count<st.size()){
                    if(st.top() == q.front()){
                            st.pop();
                            q.pop();
                            count=0;
                    }else{
                            int tmp = q.front(); q.pop();
                            q.push(tmp);
                            count++;
                    }
            }
            return count;
    }
};