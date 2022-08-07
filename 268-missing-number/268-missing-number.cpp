class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        sort(nums.begin(),nums.end());
       // int x=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                x=x+1;
                //break;
            }
        }
        return x;
    }
};