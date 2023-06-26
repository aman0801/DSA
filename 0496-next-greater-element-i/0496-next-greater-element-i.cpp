class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        bool found = false;
        int maxi = -1;
        
        for(auto i:nums1){
            for(auto j:nums2){
                if(found && j>i){
                    maxi = j;
                    // ans.push_back(maxi);
                    break;
                }else if(j == i){
                    found = true;
                }
            }
            ans.push_back(maxi);
            found = false;
            maxi = -1;
        }
        return ans;
    }
};