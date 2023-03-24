class Solution {
public:
    int compress(vector<char>& chars) {
        // int ans;
        int count = 1;
        vector<char>ans;
        chars.push_back(' ');
        for(int i=0; i<chars.size()-1; i++){
            if(chars[i] == chars[i+1]){
                count++;
            }else{
                if(count==1){
                    ans.push_back(chars[i]);
                    continue;
                }
                ans.push_back(chars[i]);
                string temp=to_string(count);
                for(auto ch:temp){
                    ans.push_back(ch);
                }
                count = 1;
            }
            
        }
        chars = ans;
        return ans.size();
        
    }
};