class Solution {
public:
    int numJewelsInStones(string j, string s) {
        unordered_map<char,int>mp;
        
        int c =0;
        for(auto i:j){
            mp[i++];
        }
        
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                // mp[s[i]]+=1;
                c++;
            }
        }
        // for(int i=0;i<j.size();i++) c+=mp[j[i]];
        return c;
    }
};