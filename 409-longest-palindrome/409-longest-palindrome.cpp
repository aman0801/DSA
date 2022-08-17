class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int ans=0;
        int odd=0;
        for(auto i: s){
            mp[i]++;
        }
        
        for(auto i: mp){
            if(i.second%2==0){
                ans=ans+i.second;
            }else{
                odd=1;
                if(i.second>1)ans+=i.second-1;
            }
        }
        return ans + odd;
    }
};