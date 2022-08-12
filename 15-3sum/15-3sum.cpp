class Solution {
public:
   // vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>a;
//         int n=nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<n-2;i++){
//             for(int j=i+1;j<n-1;j++){

//                 for(int k=j+1;k<n;k++){
                    
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         a.insert({nums[i],nums[j],nums[k]});
//                     }
//                 }
//             }
//         }
//          vector<vector<int>>ans(a.begin(),a.end());
//         return ans;
        vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
        
    }
};