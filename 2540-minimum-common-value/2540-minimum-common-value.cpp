class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(nums1.begin(), nums1.end());
            for(auto& i:nums2){
                    if(st.find(i) != st.end()){
                            return i;
                    }
            }
            return -1;
    }
};