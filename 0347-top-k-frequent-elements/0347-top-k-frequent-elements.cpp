class Solution {
public:
    
    static bool cmp(pair<int, int>&a, pair<int, int>&b){
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        // vector<pair<int, int> >vec(mp.begin(), mp.end());
        vector<int> ans;
        
        for(auto &i: nums){
            mp[i]++;
        }
        vector<pair<int, int> >vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);
        
         for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }
        
        return ans;
        
    }
};