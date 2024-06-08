class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
            unordered_map<int, int>mp;
            mp[0] = -1;
            int sum=0;
            for(int i=0; i<nums.size(); i++){
                    sum = sum + nums[i];
                    int tmp = sum%k;
                    if(mp.find(tmp)!=mp.end()){
                            if(i-mp[tmp]>=2){
                                    return true;
                            }
                    }else{
                            mp[tmp] = i;
                    }
            }
            return false;
    }
};