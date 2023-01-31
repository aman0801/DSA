class Solution {
public:
    
    vector<int>find(unordered_map<int, vector<int>>adj, int n, vector<int>inD){
        queue<int>q;
        vector<int>ans;
        int count = 0;
        for(int i=0; i<n; i++){
            if(inD[i] == 0){
                ans.push_back(i);
                count++;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v:adj[u]){
                inD[v]--;
                
                if(inD[v] == 0){
                    ans.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }
        
        if(count == n)
            return ans;
        
        return {};
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
        
        vector<int>inD(numCourses, 0);
        
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            
            adj[b].push_back(a);
            
            inD[a]++;
        }
        
        return find(adj, numCourses, inD);
        
    }
};