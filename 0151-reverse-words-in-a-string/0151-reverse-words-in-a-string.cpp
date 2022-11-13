class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        string ans;
        while(i<s.length()){
          while(i<s.length() and s[i]==' ')i++;
          if(i>=s.length())break;
          int j=i+1;
          while(j<s.length() and s[j]!=' ')j++;
        
         string sub = s.substr(i,j-i);
         if(ans.length() == 0)ans = sub;
         else ans = sub + " " + ans;
         i = j+1;
        }
        return ans;
    }
};