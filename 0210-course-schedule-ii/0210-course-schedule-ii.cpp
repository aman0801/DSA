class Solution {
public:
    bool hasCycle;
    
    void dfs(unordered_map<int, vector<int>>&adj, vector<bool>&vis, vector<bool>&InRec, stack<int>&st, int u){
        vis[u] = true;
        InRec[u] = true;
        
        for(int &v:adj[u]){
            if(InRec[v]==true){
                hasCycle=true;
                return;
            }
            if(!vis[v]){
                dfs(adj, vis, InRec, st, v);
            }
        }
        st.push(u);
        InRec[u] = false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses, false);
        vector<bool>InRec(numCourses, false);
        unordered_map<int, vector<int>>adj;
        hasCycle = false;
        
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }
        
        stack<int>st;
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                dfs(adj, vis, InRec, st, i);
            }
        }
        
        if(hasCycle == true){
            return {};
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};