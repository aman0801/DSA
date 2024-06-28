class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
            vector<int>arr(n, 0);
            for(auto& it:roads){
                    int a = it[0];
                    int b = it[1];
                    
                    arr[a]++;
                    arr[b]++;
            }
            sort(arr.begin(), arr.end());
            long long ans=0;
            long long val=1;
            for(int i=0; i<n; i++){
                    ans = ans + (val*arr[i]);
                    val++;
            }
            return ans;
    }
};