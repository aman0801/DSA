class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if (k <= 1) return 0;
            int ans=0;
            int pd=1;
            int i=0;
            int j=0;
            while(i<nums.size()){
                    pd=pd*nums[i];
                    while(pd>=k){
                            pd=pd/nums[j];
                            j++;
                    }
                    ans=ans+(i-j+1);
                    i++;
            }
            return ans;
    }
};