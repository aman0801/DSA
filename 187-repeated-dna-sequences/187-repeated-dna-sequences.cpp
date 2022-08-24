class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>st;
        unordered_map<string,int>mp;
        
        if(s.size()<9){
            return st;
        }
        
        for(int i=0;i<s.size()-9;i++){
            mp[s.substr(i,10)]++;
        }
        
        for(auto i:mp){
            if(i.second>1){
                st.push_back(i.first);
            }
        }
        return st;
    }
};