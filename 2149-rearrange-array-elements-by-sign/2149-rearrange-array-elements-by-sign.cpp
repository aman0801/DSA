class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
            vector<int>ans(nums.size());
            int pos = 0;
            int neg = 1;
            
            for(int i=0; i<nums.size(); i++){
                    if(nums[i]>0){
                            ans[pos] = nums[i];
                            pos = pos + 2;
                    }else{
                            ans[neg] = nums[i];
                            neg = neg + 2;
                    }
            }
            return ans;
    }
};