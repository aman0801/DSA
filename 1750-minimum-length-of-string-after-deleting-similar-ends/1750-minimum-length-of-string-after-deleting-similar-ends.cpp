class Solution {
public:
    int minimumLength(string s) {
            int i=0;
            int j=s.length()-1;
            
            while(i<j){
                    if(s[i] == s[j]){
                            char a = s[i];
                            
                            while(i<=j && a == s[j]){
                                    j--;
                            }
                            while(i<=j && a == s[i]){
                                    i++;
                            }
                    }else{
                            return j-i+1;
                    }
            }
            return j-i+1;
    }
};