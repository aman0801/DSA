class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int temp = 0;
        
        for(auto i:gain){
            temp = temp+i;
            ans = max(ans, temp);
        }
        return ans;
    }
};