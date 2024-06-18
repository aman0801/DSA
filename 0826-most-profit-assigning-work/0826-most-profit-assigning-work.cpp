class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
            vector<pair<int, int>>arr;
            for(int i=0; i<profit.size(); i++){
                    arr.push_back({difficulty[i], profit[i]});
            }
            sort(arr.begin(), arr.end());
            
            for(int i=1; i<arr.size(); i++){
                    arr[i].second = max(arr[i].second, arr[i-1].second);
            }
            
            int ans=0;
            for(int i=0; i<worker.size(); i++){
                    int lvl = worker[i];
                    int l = 0, r = arr.size()-1;
                    int maxi = 0;
                    while(l<=r){
                            int mid = l + (r-l)/2;
                            if(arr[mid].first<=lvl){
                                    maxi = max(maxi, arr[mid].second);
                                    l = mid+1;
                            }else{
                                    r = mid-1;
                            }
                    }
                    ans = ans + maxi;
            }
            return ans;
    }
};