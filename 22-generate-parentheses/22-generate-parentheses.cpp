class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
          findAll(ans, "", n, 0);
        return ans;
    }
    
    void findAll(vector<string>&a, string b, int open, int close){
        if(open==0 and close==0){
            a.push_back(b);
            return;
        }
        
        if(open>0){
            findAll(a, b+"(", open-1, close+1);
        }
        if(close>0){
            findAll(a, b+")", open, close-1);
        }
        
    }
    
};
