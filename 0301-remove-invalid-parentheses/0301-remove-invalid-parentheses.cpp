class Solution {
public:
    vector<string>ans;
    unordered_map<string, int>mp;
        int isValid(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(')');
                }
                else if(st.top()==')'){
                    st.push(')');
                }
                else if(st.top()=='('){
                    st.pop();
                }
            }
        }
        return st.size();
    }
    
    void solve(string s, int size){
        if(mp[s]!=0){
            return;
        }else{
            mp[s]++;
        }
        
        if(size<0){
            return;
        }
        if(size == 0){
            if(!isValid(s)){
                ans.push_back(s);
            }else{
                return;
            }
        }
        
        for(int i=0; i<s.size(); i++){
            string l = s.substr(0,i);
            string r = s.substr(i+1);
            solve(l+r, size-1);
        }
        
    }
    
    vector<string> removeInvalidParentheses(string s) {
        solve(s, isValid(s));
        return ans;
    }
};