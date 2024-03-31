class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n1=-1;
            int n2=-1;
            int ci=-1;
            long long ans=0;
            for(int i=0; i<nums.size(); i++){
                    if(nums[i]<minK || nums[i]>maxK){
                            ci=i;
                    }
                    
                    if(nums[i]==minK){
                            n1=i;
                    }
                    if(nums[i]==maxK){
                            n2=i;
                    }
                    long long small = min(n1, n2);
                    long long tmp = small-ci;
                    if(tmp>0){
                            ans=ans+tmp;
                    }
            }
            return ans;
    }
};