class Solution {
public:
    string removeKdigits(string num, int k) {
            if(num.length() <= k)return "0";
            stack<char>st;
            st.push(num[0]);
            for(int i=1; i<num.length(); i++){
                    while(k>0 && !st.empty() && num[i]<st.top()){
                            st.pop();
                            k--;
                    }
                    st.push(num[i]);
                    if(st.size()==1 && num[i]=='0'){
                            cout<<st.top()<<endl;
                            st.pop();
                    }
            }
            while(k && !st.empty()){
                    --k;
                    st.pop();
            }
            string ans="";
            while(!st.empty()){
                    char tmp=st.top(); st.pop();
                    ans.push_back(tmp);
            }
            if(ans==""){
                    return "0";
            }
             reverse(ans.begin(),ans.end());
            return ans;
    }
};