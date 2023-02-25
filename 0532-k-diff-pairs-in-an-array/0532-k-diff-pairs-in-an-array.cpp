class Solution {
public:
    
    int search(vector<int>&nums, int s, int f){
        int e=nums.size()-1;
        while(s<=e){
            int m = (s+e)/2;
            if(f == nums[m]){
                return m;
            }else if(f > nums[m]){
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return -1;
    }
    
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int> >ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(search(nums, i+1, k+nums[i]) != -1){
                ans.insert({nums[i], nums[i]+k});
            }
        }
        return ans.size();
    }
};