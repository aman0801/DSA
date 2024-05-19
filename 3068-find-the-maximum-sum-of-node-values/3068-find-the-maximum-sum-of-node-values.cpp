class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
            long long sum = 0;
            int count = 0;
            int loss = INT_MAX;
            
            for(long long it:nums){
                    if((it^k)>it){
                            count++;
                            sum = sum + (it^k);
                    }else{
                            sum = sum + it;
                    }
                    loss = min((long long)loss, abs(it-(it^k)));
            }
            
            if(count%2!=0){
                    return (sum-loss);
            }
            return sum;
    }
};