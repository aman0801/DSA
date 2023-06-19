class Solution {
public:
    
    void solve(string digits, unordered_map<int, string>mp, string output, vector<string>& ans, int idx){
        if(output.size() == digits.size()){
            ans.push_back(output);
            return;
        }
        
        string temp = mp[digits[idx]-'0'];
        
        for(int i = 0; i < temp.size(); i++) {
            output.push_back(temp[i]);
            solve(digits, mp, output, ans, idx+1);
            output.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits == "")
            return {};
        
        unordered_map<int, string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        // string ans;
        vector<string>ans;
        string output;
        solve(digits, mp, output, ans, 0);
        return ans;
    }
};
