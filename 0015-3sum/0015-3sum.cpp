class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){  
            if(i>0 && nums[i] == nums[i-1])continue;
            int j=i+1, k=nums.size()-1;
            
            while(j<k){
                int temp = nums[i]+nums[j]+nums[k];
                if(temp == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }

                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }else if(temp>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};