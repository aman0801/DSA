class Solution {
public:
    int maxDepth(string s) {
        // stack<char>s;
        int count=0;
        int temp = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                temp++;
            }else if(s[i] == ')'){
                count = max(temp, count);
                temp--;
            }
        }
        return count;
    }
};