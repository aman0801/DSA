class Solution {
public:
        
    int count1 = 0;
        
 bool isPal(string s, int i, int j) {
         while (i <= j) {
                 if (s[i] != s[j]) {
                         return false;
                         count1++;
                 }
                 i++;
                 j--; 
         }
         return true;
 }   
        
    int countSubstrings(string s) {
            int count = 0;
            for(int i=0; i<s.length(); i++){
                    for(int j=i; j<s.length(); j++){
                            if(isPal(s, i, j)){
                                    count++;
                            }
                            if(count1==2){
                                 break;
                                    count1=0;   
                            }
                    }
            }
            return count;
    }
};