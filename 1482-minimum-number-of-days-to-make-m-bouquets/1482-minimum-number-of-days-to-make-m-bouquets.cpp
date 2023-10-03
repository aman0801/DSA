class Solution {
public:
    
    bool isPoss(vector<int>& arr, int mid, int m, int k){
        int ans = 0;
        int count = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=mid){
                count++;
            }else{
                ans = ans + (count/k);
                count = 0;
            }
        }
        ans = ans + (count/k);
        return ans>=m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int ans = 0;
        
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); 
        if (val > n) return -1; 
        for(auto& i:bloomDay){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        
        while(mini<=maxi){
            int mid = (mini+maxi)/2;
            
            if(isPoss(bloomDay, mid, m, k)){
                ans = mid;
                maxi = mid-1;
            }else{
                mini = mid+1;
            }
        }
        return ans;
    }
};

