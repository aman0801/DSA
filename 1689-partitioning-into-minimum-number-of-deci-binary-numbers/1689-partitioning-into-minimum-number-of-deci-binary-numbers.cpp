class Solution {
public:
    int minPartitions(string n) {
        // int a = stoi(n);
        int ans = 0;
        
        for(auto i : n){
            int temp = i-'0';
            ans = max(ans, temp);
        }
        return ans;
    }
};