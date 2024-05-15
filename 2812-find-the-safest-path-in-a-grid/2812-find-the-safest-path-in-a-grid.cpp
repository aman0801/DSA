class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};    
        
    bool check(vector<vector<int>>& dist, int sf){
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            
            q.push({0, 0});
            visited[0][0] = true;
            if(dist[0][0] < sf){
                    return false;
            }
            
            while(!q.empty()){
                    int curr_i = q.front().first;
                    int curr_j = q.front().second;
                    q.pop();
                    
                    if(curr_i == n-1 && curr_j == n-1) {
                            return true;
                    }
                    
                    for(vector<int>& dir : directions) {
                            int new_i = curr_i + dir[0];
                            int new_j = curr_j + dir[1];
                            
                            if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visited[new_i][new_j] != true){
                                    if(dist[new_i][new_j] < sf){
                                            continue;
                                    }
                                    q.push({new_i, new_j});
                                    visited[new_i][new_j] = true;
                            }
                    }
            }
            return false;
    }    
        
    int maximumSafenessFactor(vector<vector<int>>& grid) {
            n = grid.size();
            vector<vector<int>>dist(n, vector<int>(n, -1));
            vector<vector<bool>>vis(n, vector<bool>(n, false));
            queue<pair<int, int>>q;
            
            for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                            if(grid[i][j] == 1){
                                    q.push({i, j});
                                    vis[i][j] = true;
                            }
                    }
            }
            
            int lvl=0;
            while(!q.empty()){
                    int sz = q.size();
                    while(sz--){
                            int _i = q.front().first;
                            int _j = q.front().second;
                            q.pop();
                            dist[_i][_j] = lvl;
                            for(auto& it:directions){
                                    int i_ = _i + it[0];
                                    int j_ = _j + it[1];
                                    
                                    if(i_ < 0 || i_ >= n || j_ < 0 || j_ >= n || vis[i_][j_]==true){
                                            continue;
                                    }
                                    
                                    q.push({i_, j_});
                                    vis[i_][j_] = true;
                            }
                    }
                    lvl++;
            }
            
            int l = 0;
            int r = 400;
            int result = 0;

            while(l <= r) {
                    int mid_sf = l + (r-l)/2;
                    
                    if(check(dist, mid_sf)) {
                            result = mid_sf;
                            l = mid_sf+1;
                    } else {
                            r = mid_sf-1;
                    }
            }

        return result;
            
    }
};