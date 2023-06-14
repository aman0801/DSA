class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.size()%2!=0){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else if(st.empty() || st.top() == '(' && s[i] != ')'){
                // st.pop();
                return false;
            }else if(st.empty() || st.top() == '{' && s[i] != '}'){
                // st.pop();
                return false;
            }else if(st.empty() || st.top() == '[' && s[i] != ']'){
                // st.pop();
                return false;
            }else{
                st.pop();
            }
        }
        return st.empty();
    }
};

// stack<char> sack;
//      int n = s.size();
//      for(int i=0;i<n;i++)
//      {   
//          if(s[i]=='(' || s[i]=='{' || s[i]=='[')
//          { 
//            sack.push(s[i]);
//            continue;
//          }
//          if(sack.empty())
//              return false;
//          char x = sack.top();
//          if((x=='(' && s[i]==')') || (x=='{' && s[i]=='}') || (x=='[' && s[i]==']'))
//              sack.pop();
//          else
//             return false;
//      } 
//      if(sack.empty())
//          return true;
//      return false;