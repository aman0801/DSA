class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            }else if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            char a = st.top();
            ans.push_back(a);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};