class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans;
        for(int i=0; i<s.size(); i++){
            // if(st.empty()){
                // st.push(s[i]);
            // }
            if(s[i] == '*'){
                st.pop();
                // st.pop();
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            char a = st.top();
            ans.push_back(a);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};