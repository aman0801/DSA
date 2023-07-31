class Solution {
public:
        bool isPal(string s, int st, int e){
                while(st<=e){
                        if(s[e--]!=s[st++]){
                                return false;
                        }
                }
                return true;
        }
        
    void solve(string s, vector<string>& out, vector<vector<string>>& ans, int idx) {
        if (idx == s.size()) {
            ans.push_back(out);
            return;
        }

        for(int i=idx; i<s.size(); i++){
                if(isPal(s, idx, i)){
                        out.push_back(s.substr(idx, i-idx+1));
                        solve(s, out, ans, i+1);
                        out.pop_back();
                }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> out;
        vector<vector<string>> ans;
        solve(s, out, ans, 0);
        return ans;
    }
};
