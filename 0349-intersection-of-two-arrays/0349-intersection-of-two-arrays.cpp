class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int>ans;
            set<int>store;
        for(int i=0; i<nums1.size(); i++){
                for(int j=0; j<nums2.size(); j++){
                        if(nums1[i] == nums2[j]){
                                store.insert(nums1[i]);
                        }
                }
        }
            for(auto i:store){
                    ans.push_back(i);
            }
            return ans;
    }
};