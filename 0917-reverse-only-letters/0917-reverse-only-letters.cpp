class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(!isalpha(ans[i])){
                continue;
            }
            while(!isalpha(s[j])){
                j++;
            }
            ans[i]=s[j];
            j++;
        }
        return ans;
    }
};