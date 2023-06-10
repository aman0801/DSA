class Solution {
public:
    
    int lb(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int lob = nums.size();
        
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                lob = m;
                r = m - 1;
            }else if(nums[m] > target){
                r = m-1; 
            }else{
                l = m+1;
            }
        } 
        return lob;
    }
    
    int ub(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int upb = -1;
        
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                upb = m;
                l = m + 1;
            }else if(nums[m] > target){
                r = m-1; 
            }else{
                l = m+1;
            }
        } 
        return upb;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
        int lob = lb(nums,target);
        int upb = ub(nums,target);
        //cout<<lb<<" "<<ub<<endl;
        vector<int> res;
        for(int i=lob;i<=upb;++i) res.push_back(i);
        return res;
    }
};

