class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
//             Brute force method
//         sort(nums.begin(),nums.end());
        
//         for(int i=1;i<size(nums);i++){
//             if(nums[i-1]==nums[i])
//                 return true;
//              }
//             return false;
    
//     }
           
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        for(int x:nums){
            if(mp[x]>=2){
                return true;
            }
        }
        return false;
        
    }
};