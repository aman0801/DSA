class Solution {
public:
    
    bool isPal(string &s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
        
    }
    
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(isPal(s, i, j)){
                    string t = s.substr(i, j-i+1);
                    
                    if(ans.size()<t.size()){
                        ans = t;
                    }
                    
                }
            }
        }
        return ans;
    }
};