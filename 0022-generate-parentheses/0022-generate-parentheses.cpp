class Solution {
public:
    
    void solve(int n, vector<string>&ans, string output, int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        
        if(open > 0){
            output = output + '(';
            // solve(n, ans, output+'(', open-1, close);
            solve(n, ans, output, open-1, close);
            output.pop_back();
        }
        
        if(open < close){
            output = output + ')';
            // solve(n, ans, output+')', open, close-1);
            solve(n, ans, output, open, close-1);
            output.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output = "";
        int open = n;
        int close = n;
        solve(n, ans, output, open, close);
        return ans;
    }
};