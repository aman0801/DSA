class Solution {
public:
    
    int solve(vector<int>& nums, int k){
        int i=0,j=0,ans=0;
        unordered_map<int, int>mp;
        
        while(i<nums.size()){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            ans = ans+(i-j+1);
            i++;
        }
        return ans;    
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k)-solve(nums, k-1);
    }
};