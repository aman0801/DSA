class Solution {
public:
    string customSortString(string order, string s) {
            unordered_map<char, int>mp;
            for(auto& it:s){
                    mp[it]++;
            }
            string ans;
            for(auto& it:order){
                    if(mp.find(it)!=mp.end()){
                            ans = ans + string(mp[it], it);
                            mp.erase(it);
                    }
            }
            for(auto& it:mp){
                    ans = ans +string(it.second, it.first);
            }
            return ans;
    }
};