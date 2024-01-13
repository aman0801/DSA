class Solution {
public:
    int minSteps(string s, string t) {
            unordered_map<int, int>mp1;
            unordered_map<int, int>mp2;
            
            for(auto& i:s){
                    mp1[i]++;
            }
            for(auto& i:t){
                    mp2[i]++;
            }
            
            int ans = 0;
            for(auto& i:mp2){
                    if(i.second-mp1[i.first]>0){
                            ans = ans+i.second-mp1[i.first];
                    }
            }
            return ans;
    }
};