class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int ans = 0;
        for(auto &i:operations){
           if(i == "C"){
               st.pop();
           }else if(i == "D"){
               // string x = st.top();
               st.push(2*st.top());
           }else if(i == "+"){
               int a = st.top();
               st.pop();
               int b = st.top();
               // st.pop();
               // string c = a+b;
               st.push(a);
               st.push(a+b);
               // st.push(c);
           }else{
               st.push(stoi(i)); 
           }
        }
        
         while(st.size() != 0)
        {
            ans += st.top();
            st.pop();
        }
        return ans;
        
    }
};