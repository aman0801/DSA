class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
         int n = nums.size();
        int m = queries.size();
        vector<int>ans(m,0);
        
        sort(nums.begin(), nums.end());
        vector<int>pre;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            pre.push_back(sum);
        }
        
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<nums.size();j++){
                if(pre[j]<=queries[i]){
                    ans[i] = j+1;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};