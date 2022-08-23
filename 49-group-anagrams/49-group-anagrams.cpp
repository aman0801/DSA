class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       string ch = "";
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
       //vreated map with key as a  string and value as a vector  of string
            for(int i=0;i<strs.size();i++){
            ch=strs[i];
            sort(ch.begin(),ch.end());
            mp[ch].push_back(strs[i]);
        }
        for(auto i:mp){
            ans.push_back(i.second);
            //way to push in a 2d array from 1d array
        }
        return ans;
    }
};