class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=s.size()/2; i>=1; i--){
                if(s.size()%i == 0){
                        int t = s.size()/i;
                        string patt = s.substr(0, i);
                        string temp;
                        while(t--){
                                temp = temp + patt;
                        }
                        if(s == temp)return true;
                }
        }
            return false;
    }
};