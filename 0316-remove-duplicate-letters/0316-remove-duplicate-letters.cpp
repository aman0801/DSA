class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last(26);
        vector<bool>vis(26);
        string ans = "";
        
        for(int i=0; i<s.size(); i++){
            last[s[i] - 'a'] = i;
        }
        
        for(int i=0; i<s.size(); i++){
            if(vis[s[i] - 'a']){
                continue;
            }
            
            while(!ans.empty() && ans.back() > s[i] && last[ans.back() - 'a'] > i){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        return ans;
    }
};