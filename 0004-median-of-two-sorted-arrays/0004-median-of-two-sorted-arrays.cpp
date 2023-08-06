class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size()+nums2.size());
            int i=0; 
            int j=0;
            int k=0;
            while(i<nums1.size() && j<nums2.size()){
                    if(nums1[i]<nums2[j]){
                            ans[k++] = nums1[i++];
                    }else{
                            ans[k++] = nums2[j++];
                    }
            }
            while(i<nums1.size()){
                    ans[k++] = nums1[i++];
            }
            while(j<nums2.size()){
                    ans[k++] = nums2[j++];
            }
            double sol = 0;
            if(ans.size()%2!=0){
                    sol = ans[ans.size()/2];
            }else{
                  sol = (ans[ans.size() / 2 - 1] + ans[ans.size() / 2]) / 2.0;  
            }
            return sol;
    }
};