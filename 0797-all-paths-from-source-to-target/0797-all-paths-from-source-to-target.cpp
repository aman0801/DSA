class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        int s = 0;
        path.push_back(s);
        
        queue<vector<int> >q;
        q.push(path);
        
        while(!q.empty()){
            path=q.front();
            q.pop();
            
            int val=path.back();
            
            if(val == graph.size()-1){
                ans.push_back(path);
            }
            
            for(int &i:graph[val]){
                vector<int>v(path);
                v.push_back(i);
                q.push(v);
            }
            
        }
        return ans;
    }
};