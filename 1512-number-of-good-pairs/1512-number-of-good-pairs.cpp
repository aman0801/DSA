class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int>mp;
        int count = 0;
        
        for(int i:nums){
                count = count + mp[i];
                mp[i]++;
        }
        return count;
    }
};