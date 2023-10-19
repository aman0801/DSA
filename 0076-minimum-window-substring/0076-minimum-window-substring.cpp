class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.length() > s.length()){
            return "";
        }
        
        map<char, int>mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int i=0,j=0,ans=INT_MAX,len=t.length(), start=0;
        
        while(i<s.length()){
            if(mp[s[i]] > 0){
                len--;
            }
            mp[s[i]]--;
            
            while(len == 0){
                if(ans>i-j+1){
                    ans = i-j+1;
                    start=j;
                }
                mp[s[j]]++;
                if(mp[s[j]]>0){
                    len++;
                }
                j++;
            }
            i++;
        }
        if(ans == INT_MAX){
            return "";
        }
        return s.substr(start, ans);
        
    }
};