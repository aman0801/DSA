class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // sort(nums.begin(),nums.end());
//         int sum,sum1;
//         vector<int>a;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     sum=i;
//                     sum1=j;
                    
//                 }
//             }
//         }
//         a.push_back(sum);
//         a.push_back(sum1);
//         return {sum,sum1};
//         // or return a;
        
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[target-nums[i]]>0){
                return {i,mp[target-nums[i]]-1};
            }
            mp[nums[i]]=i+1;
        }
        return {};
    }
};