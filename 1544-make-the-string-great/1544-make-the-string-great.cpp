class Solution {
public:
    string makeGood(string s) {
            stack<char>st;
            st.push(s[0]);
            for(int i=1; i<s.length(); i++){
                    if(st.empty()){
                            st.push(s[i]);
                    }else{
                            if(abs(s[i]-st.top()) == 32){
                                    st.pop();
                            }else{
                                    st.push(s[i]);
                            }
                    }
            }
            string ans;
            while(!st.empty()){
                    ans = ans + st.top();
                    st.pop();
            }
            reverse(begin(ans), end(ans));
            return ans;
    }
};