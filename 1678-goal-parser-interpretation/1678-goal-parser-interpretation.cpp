class Solution {
public:
    string interpret(string c) {
        string ans = "";
        
        for(int i=0;i<c.size();i++){
            if(c[i]=='G'){
                ans = ans+c[i];
                continue;
            }
            if(c[i]=='(' && c[i+1]==')')
			ans+='o', i++;
		if(c[i]=='(' && c[i+1]=='a')
			ans+="al", i+=3;
        }
        return ans;
    }
};