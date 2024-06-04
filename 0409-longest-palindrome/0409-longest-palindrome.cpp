class Solution {
public:
    int longestPalindrome(string s) {
            unordered_map<char, int>mp;
            int odd=0;
            for(auto& it:s){
                    mp[it]++;
            }
            int ans=0;
            for(auto& it:mp){
                    if(it.second%2 == 0){
                            ans = ans + it.second;
                    }else{
                            odd=1;
                            if(it.second>1){
                                    ans = ans + it.second-1;
                            }
                    }
            }
            return ans+odd;
    }
};