class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count = 0;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(!st.empty() && st.top() == '[' && s[i] == ']'){
                st.pop();
            }else{
                st.push(s[i]);
                count++;
            }
        }
        // cout << count;
        int t=st.size()/2;
        if(t%2==0)
            return t/2;
        return (t+1)/2;
    }
};