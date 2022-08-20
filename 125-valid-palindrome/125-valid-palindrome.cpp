class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()<=1){
            return true;
        }
        int st=0;
        int n=s.length()-1;
        while(st<n){
        while(st<n and !isalnum(s[st])){
            st++;
        }
        while(st<n and !isalnum(s[n])){
            n--;
        }
        if(st < n && tolower(s[st]) != tolower(s[n])) return false;
            st++;
            n--;
        }
        
        return true;
    }
};