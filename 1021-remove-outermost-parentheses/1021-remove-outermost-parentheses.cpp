class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(st.size() > 0){
                    ans.push_back(s[i]);
                }
                st.push('(');
            }else{
                if(st.size() > 1){
                    ans.push_back(s[i]);
                }
                st.pop();
            }
        }
        return ans;
    }
};