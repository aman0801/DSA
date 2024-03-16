class Solution {
public:
    int findMaxLength(vector<int>& nums) {
            unordered_map<int, int>mp;
            mp[0]=-1;
            int ans=INT_MIN;
            int sum=0;
            
            for(int i=0; i<nums.size(); i++){
                    int val=0;
                    if(nums[i]==0){
                            val=-1;
                    }else{
                            val=1;
                    }
                    
                    sum=sum+val;
                    if(mp.find(sum)!=mp.end()){
                            ans=max(ans, i-mp[sum]);
                    }else{
                            mp[sum]=i;
                    }
            }
            if(ans == INT_MIN){ 
                    return 0;
            }
            return ans;
    }
};