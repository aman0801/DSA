class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
            int count=0;
            int past=0;
            vector<bool>vis(nums.size(), false);
            for(int i=0; i<nums.size(); i++){
                    if(i>=k && vis[i-k] == true){
                            past--;
                    }
                    if(past%2 == nums[i]){
                            if(i+k>nums.size()){
                                    return -1;
                            }
                            past++;
                            vis[i] = true;
                            count++;
                    }
            }
            return count;
    }
};