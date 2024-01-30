class Solution {
public:
        
    int oper(int a, int b, string ch){
            if(ch == "+"){
                    return a+b;
            }
            if(ch == "-"){
                    return b-a;
            }
            if(ch == "*"){
                    return a*b;
            }
            if(ch == "/"){
                    return b/a;
            }
            return 0;
    }    
        
    int evalRPN(vector<string>& tokens) {
            stack<int>st;
            for(auto& it:tokens){
                    if(it == "+" || it == "-" || it == "*" || it == "/"){
                            int a = st.top(); st.pop();
                            int b = st.top(); st.pop();
                            
                            int temp = oper(a, b, it);
                            st.push(temp);
                    }else{
                            st.push(stoi(it));
                    }
            }
            return st.top();
    }
};