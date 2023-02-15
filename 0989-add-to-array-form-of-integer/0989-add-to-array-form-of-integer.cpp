class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n-1;
        
        vector<int>ans;
        
        while(i>=0 || k>0){
            if(i>=0){
                ans.push_back((num[i]+k)%10);
                k = (num[i]+k)/10;
            }else{
                ans.push_back(k%10);
                k = k/10;
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};