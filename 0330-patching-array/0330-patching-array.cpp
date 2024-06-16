class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
            int i=0;
            long sum=0;
            int ans=0;
            while(sum<n){     
                    if(i<nums.size() && nums[i]<=sum+1){
                            sum = sum + nums[i];
                            i++;
                    }else{
                            sum = sum + (sum + 1);
                            ans++;
                    }
            }
            return ans;
    }
};