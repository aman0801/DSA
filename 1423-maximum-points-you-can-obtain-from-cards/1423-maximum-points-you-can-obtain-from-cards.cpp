class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum=0, ans=0;
        for(int i=0; i<k; i++){
            sum = sum+arr[i];
        }
        ans = sum;
        
        for(int i=k-1,j=arr.size()-1; i>=0; i--,j--){
            sum = sum-arr[i];
            sum = sum+arr[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};