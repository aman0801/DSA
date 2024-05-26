class Solution {
public:
    bool checkRecord(string s) {
            int p=0;
            int a=0;
            if(s[0] == 'A')a++;
            if(s[0] == 'A' && s[1] == 'A')return false;
            for(int i=1; i<s.length()-1; i++){
                    if(s[i] == 'A'){
                            a++;
                    }
                    if(s[i] == 'L' && s[i-1] == 'L' && s[i+1] == 'L'){
                            return false;
                    }
            }
            if(a>=2){
                    return false;
            }
            return true;
    }
};