class Solution {
public:
    int beautySum(string s) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            int ans = 0;
            
            for(int i=0; i<s.length(); i++){
                    unordered_map<char, int>mp;
                    for(int j=i; j<s.length(); j++){
                            mp[s[j]]++;
                            for(auto& it:mp){
                                    mini = min(mini, it.second);
                                    maxi = max(maxi, it.second);
                            }
                            ans = ans + (maxi-mini);
                            mini = INT_MAX;
                            maxi = INT_MIN;
                    }
                    mp.clear();
            }
            return ans;
    }
};