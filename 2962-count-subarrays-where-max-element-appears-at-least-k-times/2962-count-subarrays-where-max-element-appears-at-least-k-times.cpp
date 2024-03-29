class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
            int maxE = *max_element(nums.begin(), nums.end());
            int i=0;
            int j=0;
            long long ans=0;
            int freq=0;
            while(j<nums.size()){
                    if(nums[j] == maxE){
                            freq++;
                    }
                    while(freq>=k){
                            ans=ans+(nums.size()-j);
                            if(nums[i] == maxE){
                                    freq--;
                            }
                            i++;
                    }
                    j++;
            }
            return ans;
    }
};