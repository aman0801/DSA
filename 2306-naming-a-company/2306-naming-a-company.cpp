class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>iniGr[26];
        
        for(auto& idea:ideas){
            iniGr[idea[0]-'a'].insert(idea.substr(1));
        }
        
        long long count = 0;
        
        for(int i=0; i<25; i++){
            for(int j=i+1; j<26; j++){
                int comm = 0;
                
                for(auto& idea:iniGr[i]){
                    if(iniGr[j].count(idea)){
                        comm++;
                    }
                }
               count = count + 2LL*((iniGr[i].size() - comm)*(iniGr[j].size() - comm));
            }
        }
        return count;
    }
};