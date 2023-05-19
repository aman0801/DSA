class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, int v, vector<int>&color, int node, int currCo){
        color[node] = currCo;
        
        for(int &i:graph[node]){
            if(color[i] == color[node]){
                return false;
            }
            
            if(color[i] == -1){
                int cov = 1-currCo;
                
                if(dfs(graph, v, color, i, cov) == false){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);
        
        for(int i=0; i<v; i++){
            if(color[i] == -1){
                if(dfs(graph, v, color, i, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};