// class Solution {
// public:
    
//       bool isVal(string s) {
//         stack <char>ch;
//         for(auto i:s){
//             if(i=='(' or i=='{' or i=='['){
//                 ch.push(i);
//             }else{
//                 if(i==')'){
//                     if(ch.empty() or ch.top()!='(')
//                         return false;
//                 }
//                  if(i=='}'){
//                     if(ch.empty() or ch.top()!='{')
//                         return false;
//                 }
//                  if(i==']'){
//                     if(ch.empty() or ch.top()!='[')
//                         return false;
//                 }
//                 ch.pop();
//             }
            
//         }
//         return ch.empty();
//     }
    
//     int isValid(string s){
//         stack<char> st;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='('){
//                 st.push('(');
//             }
//             else if(s[i]==')'){
//                 if(st.size()==0){
//                     st.push(')');
//                 }
//                 else if(st.top()==')'){
//                     st.push(')');
//                 }
//                 else if(st.top()=='('){
//                     st.pop();
//                 }
//             }
//         }
//         return st.size();
//     }
    
    
//     vector<string> removeInvalidParentheses(string s) {
//         int size = isValid(s);
//         vector<string>ans;
//         // solve(s, size, ans);
//         for(int i=0; size==0 && i<s.size(); i++){
//             string output = s.substr(0, i) + s.substr(i + 1);
//             if(isVal(output) == true){
//                 ans.push_back(output);
//                 size--;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    bool isValid(string s) {
        int balance = 0;
        for (char ch : s) {
            if (ch == '(') {
                balance++;
            } else if (ch == ')') {
                balance--;
                if (balance < 0) {
                    return false;
                }
            }
        }
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;

        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }

            if (found) {
                continue; 
            }

           
            for (int i = 0; i < curr.length(); i++) {
                if (curr[i] != '(' && curr[i] != ')') {
                    continue;  
                }

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        return result;
    }
};
