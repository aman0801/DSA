class Solution {
public:

    bool sort(unordered_map<int, vector<int>>&adj, int n, vector<int>&inD){
        queue<int>q;
        int count = 0;
        for(int i=0; i<n; i++){
            if(inD[i] == 0){
                count++;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v: adj[u]){
                inD[v]--;
                
                if(inD[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        
        if(count == n){
            return true;
        }
        return false;
        
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
        vector<int>inD(n, 0);

        for(auto &v: prerequisites){
            int a = v[0];
            int b = v[1];

            adj[b].push_back(a);
            inD[a]++;
        }
        return sort(adj, n, inD);
    }
};