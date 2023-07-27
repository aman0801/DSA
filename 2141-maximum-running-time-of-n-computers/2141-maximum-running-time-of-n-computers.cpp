class Solution {
public:
        typedef long long ll;
        
    bool solve(vector<int>& batteries, int n, ll mid){
            ll target = n*mid;
            ll sum = 0;
            for(int i=0; i<batteries.size(); i++){
                   target -= min((ll)batteries[i], mid);
                    if(target<=0){
                            return true;
                    }
            }
            return false;
    }
        
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(begin(batteries), end(batteries));
        long sum = 0;
        for(auto& i:batteries){
                sum = sum + i;
        }
        ll r = sum/n;
            ll ans = 0;
            while(l<=r){
                    ll mid = l+(r-l)/2;
                    if(solve(batteries, n, mid)){
                            ans = mid;
                            l = mid+1;
                    }else{
                            r = mid-1;
                    }
            }
            return ans;
    }
};