class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
            unordered_map<int, int> mp;
            vector<vector<int>> ans;
            vector<int> out;
            for(auto& i:nums){
                    mp[i]++;
            }
            
            unordered_map<int, int> temp;
            while(!mp.empty()){
                    temp = mp;
                    out.clear();
                    for(auto& i:temp){
                            mp[i.first]--;
                            out.push_back(i.first);
                            if(mp[i.first] == 0){
                                    mp.erase(i.first);
                            }
                    }
                    ans.push_back(out);
            }
            return ans;
    }
};