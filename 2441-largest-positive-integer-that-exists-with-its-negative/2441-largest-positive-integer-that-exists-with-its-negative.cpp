class Solution {
public:
    int findMaxK(vector<int>& nums) {
            unordered_map<int, int>pos, neg;
            for(auto& it:nums){
                    if(it>0){
                            pos[it]++;
                    }else{
                            neg[it]++;
                    }
            }
            int ans=-1;
            for(auto& it:pos){
                    int tmp=it.first;
                    tmp=tmp*-1;
                    if(ans<it.first && neg.find(tmp)!=neg.end()){
                            ans=it.first;
                    }
            }
            return ans;
    }
};