class Solution {
public:
    string minRemoveToMakeValid(string s) {
            int open=0;
            string tmp;
            for(int i=0; i<s.length(); i++){
                    if(s[i]=='('){
                            open++;
                            tmp.push_back(s[i]);
                    }else if(s[i]==')'){
                            if(open>0){
                                    open--;
                                    tmp.push_back(s[i]);
                            }
                    }else{
                            tmp.push_back(s[i]);
                    }
            }
            string ans;
            for(int i=tmp.length()-1; i>=0; i--){
                    if(tmp[i]=='(' && open>0){
                            open--;
                    }else{
                            ans.push_back(tmp[i]);
                    }
            }
            reverse(begin(ans), end(ans));
            return ans;
    }
};