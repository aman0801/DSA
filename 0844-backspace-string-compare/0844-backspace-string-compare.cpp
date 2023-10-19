class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        string ans1,ans2;
        
        for(int i=0; i<s.size(); i++){
            if(!s1.empty() && s[i] == '#'){
                s1.pop();
            }
            if(s[i]!='#'){
                s1.push(s[i]);
            }
        }
        
        for(int i=0; i<t.size(); i++){
            if(!s2.empty() && t[i] == '#'){
                s2.pop();
            }
            if(t[i]!='#'){
                s2.push(t[i]);
            }
        }
        while(!s1.empty()){
            ans1 = ans1+s1.top();
            s1.pop();
        }
        while(!s2.empty()){
            ans2 = ans2+s2.top();
            s2.pop();
        }
        cout << ans1 << endl << ans2<<endl;
        return ans1==ans2;
    }
};