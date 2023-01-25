class Solution {
public:
    int n;
    void dfs(vector<int>& edges, vector<bool>&vis, vector<int>&dis, int node){
        vis[node] = true;
        int v = edges[node];
        
        if(v!=-1 && !vis[v]){
            vis[v] = true;
            dis[v] = 1+dis[node];
            
            dfs(edges, vis, dis, v);
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int>dis1(n, INT_MAX);
        vector<int>dis2(n, INT_MAX);
        
        vector<bool>vis1(n, false);
        vector<bool>vis2(n, false);
        
        dis1[node1] = 0;
        dis2[node2] = 0;
        
        dfs(edges, vis1, dis1, node1);
        dfs(edges, vis2, dis2, node2);
        
        int minDisNode = -1;
        int currDis = INT_MAX;
        
        for(int i=0; i<n; i++){
            int curr = max(dis1[i], dis2[i]);
            
            if(currDis > curr){
                currDis = curr;
                minDisNode = i;
            }
        }
        return minDisNode;
    }
};