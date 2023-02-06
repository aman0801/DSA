//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>inDe(V, 0);
        int count = 0;
        queue<int>q;
        
        for(int i=0; i<V; i++){
            for(auto j:adj[i]){
                inDe[j]++;
            }
        }
        
        for(int i=0; i<V; i++){
            if(inDe[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            count++;
            
            for(auto i:adj[temp]){
                inDe[i]--;
                
                if(inDe[i] == 0){
	            q.push(i);
	           }
            }
        }
        if(count == V){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends