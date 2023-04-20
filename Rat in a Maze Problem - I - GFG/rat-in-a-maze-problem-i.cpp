//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &arr, int n, vector<vector<bool>>&vis, int i, int j){
        if((i>=0 && i<n) && (j>=0 && j<n) && (arr[i][j] == 1) && (vis[i][j] == false)){
            return true;
        }
        return false;
    }
    
    void find(vector<vector<int>> &arr, int n, int i, int j, string output, vector<vector<bool>>&vis, vector<string>&ans){
        if(i == n-1 && j == n-1){
            ans.push_back(output);
        }
        vis[i][j] = true;
        
        // for down
        if(isSafe(arr, n, vis, i+1, j)){
            find(arr, n, i+1, j, output+'D', vis, ans);
        }
        
        //for left
        if(isSafe(arr, n, vis, i, j-1)){
            find(arr, n, i, j-1, output+'L', vis, ans);
        }
        
        // for right
        if(isSafe(arr, n, vis, i, j+1)){
            find(arr, n, i, j+1, output+'R', vis, ans);
        }
        
        // for up
        if(isSafe(arr, n, vis, i-1, j)){
            find(arr, n, i-1, j, output+'U', vis, ans);
        }
        
        vis[i][j] = false;
        
    }
    
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        // Your code goes here
        string output = "";
        vector<string>ans;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        if(arr[0][0] == 0){
            return {};
        }
        if(arr[n-1][n-1] == 0){
            return {};
        }
        
        find(arr, n, 0, 0, output, vis, ans);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends