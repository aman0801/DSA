class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
            map<int, vector<pair<int, int>>>mp;
            
            for(auto& it:meetings){
                    int p1 = it[0];
                    int p2 = it[1];
                    int time = it[2];
                    
                    mp[time].push_back({p1, p2});
            }
            
            vector<bool>knows(n, false);
            knows[0] = true;
            knows[firstPerson] = true;
            
            for(auto& it:mp){
                    int t = it.first;
                    vector<pair<int, int>>tmp = it.second;
                    
                    unordered_map<int, vector<int>>adj;
                    queue<int>q;
                    unordered_set<int>vis;
                    
                    for(auto& [p1, p2]:tmp){
                            adj[p1].push_back(p2);
                            adj[p2].push_back(p1);
                            
                            if(knows[p1]==true && vis.find(p1)==vis.end()){
                                    q.push(p1);
                                    vis.insert(p1);
                            }
                            if(knows[p2]==true && vis.find(p2)==vis.end()){
                                    q.push(p2);
                                    vis.insert(p2);
                            }
                            
                    }
                    
                    while(!q.empty()){
                            int person = q.front(); q.pop();
                            for(auto& i:adj[person]){
                                    if(knows[i] == false){
                                            knows[i] = true;
                                            q.push(i);
                                    }
                            }
                    }
            }
            
            vector<int>ans;
            for(int i=0; i<n; i++){
                    if(knows[i]==true){
                            ans.push_back(i);
                    }
            }
            return ans;
    }
};