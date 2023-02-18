class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      int vertices = edges.size();
        unordered_map<int,vector<int>> adj;

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(auto pr : adj){
            if(pr.second.size() == vertices) return pr.first;
        }
        return -1;
    }
};