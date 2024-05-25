class Solution {
public:
        
    void solve(string s, vector<string>& wordDict, unordered_map<string, int>& mp, vector<string>& ans, string& tmp, int idx){
            if(idx>=s.length()){
                   ans.push_back(tmp);
                    return;
            }
            
            for(int i=idx+1; i<=s.length(); i++){
                    string word = s.substr(idx, i-idx);
                    if(mp.find(word)!=mp.end()){
                            string org = tmp;
                            if(!tmp.empty()){
                                    tmp = tmp + " ";
                            }
                            tmp = tmp + word;
                            solve(s, wordDict, mp, ans, tmp, i);
                            tmp=org;
                    }
            }
    }    
        
    vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_map<string, int>mp;
            for(auto& i:wordDict){
                    mp[i]++;
            }
            vector<string> ans;
            string tmp;
            solve(s, wordDict, mp, ans, tmp, 0);
            return ans;
    }
};