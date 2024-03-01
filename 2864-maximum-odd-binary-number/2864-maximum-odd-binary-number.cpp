class Solution {
public:
    string maximumOddBinaryNumber(string s) {
            string ans = string(s.length(), '0');
            
            int i=0;
            
            for(auto& c:s){
                    if(c == '1'){
                            if(ans[s.length()-1] == '1'){
                                    ans[i] = '1';
                                    i++;
                            }else{
                                    ans[s.length()-1] = '1';
                            }
                    }
            }
           return ans;
    }
};