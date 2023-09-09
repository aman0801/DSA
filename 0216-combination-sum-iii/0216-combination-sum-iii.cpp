class Solution {
public:
    
    void solve(vector<int>& arr, int k, int n, vector<int>& out, vector<vector<int>>& ans, int sum, int idx){
        if(out.size() == k && sum == n){
            ans.push_back(out);
            return;
        }
        
        if(sum>n || out.size()>k){
            return;
        }
        
        for(int i=idx; i<arr.size(); i++){
            sum = sum + arr[i];
            out.push_back(arr[i]);
            solve(arr, k, n, out, ans, sum, i+1);
            sum = sum - arr[i];
            out.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        for(int i=0; i<9; i++){
            arr.push_back(i+1);
        }
        vector<int>out;
        vector<vector<int>>ans;
        solve(arr, k, n, out, ans, 0, 0);
        return ans;
    }
};