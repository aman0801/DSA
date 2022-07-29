class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n);
//         for(int i=0;i<m;i++){
//             nums3.push_back(nums1[i]);
//         }
//         for(int j=0;j<n;j++){
//          nums3.push_back(nums2[j]);
//         }
         
//         sort(nums3.begin(),nums3.end());
       int k=0,i=0,j=0;
        while( i<m &&  j<n){
            if(nums1[i]<nums2[j]){
                nums3[k++]=nums1[i++];
            }else{
                nums3[k++]=nums2[j++];
            }
        }
        while(i<m){
            nums3[k++]=nums1[i++];
        }
         while(j<n){
            nums3[k++]=nums2[j++];
        }
        nums1=nums3;
        
        
    }
};