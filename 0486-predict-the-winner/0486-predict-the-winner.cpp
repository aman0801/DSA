class Solution {
public:
        
        int solve(vector<int>& nums, int i, int j){
                if(i>j){
                        return 0;
                }
                if(i==j){
                        return nums[i];
                }
                
                int for_i = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
                int for_j = nums[j] + min(solve(nums, i, j-2), solve(nums, i+1, j-1));
                
                return max(for_i, for_j);
                
        }
        
    bool PredictTheWinner(vector<int>& nums) {
//         int ans1 = 0;
//         int ans2 = 0;
//             int i=0;
//             int j=nums.size()-1;
//         while(i<j){
//                 if(nums[i]<=nums[j]){
//                         ans1 = ans1 + nums[j];
//                         cout<<ans1<<endl;
//                         j--;
//                 }else{
//                         ans1 = ans1 + nums[i];
//                         cout<<ans1<<endl;
//                         i++;
//                 }
                
//                 if(nums[i]<nums[j]){
//                         ans2 = ans2 + nums[j];
//                         cout<<ans2<<endl;
//                         j--;
//                 }else{
//                         ans2 = ans2 + nums[i];
//                         cout<<ans2<<endl;
//                         i++;
//                 }
//         }
//             if(ans1>ans2){
//                     return true;
//             }else{
//                     return false;
//             }
            
            int total = accumulate(begin(nums), end(nums), 0);
            int p1 = solve(nums, 0, nums.size()-1);
            int p2 = total-p1;
            return p1>=p2;
            
    }
};