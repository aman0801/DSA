class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<int>>& land, int i, int j, int& maxRow, int& maxCol) {
        land[i][j] = 0;
        
        maxRow = max(maxRow, i);
        maxCol = max(maxCol, j);
        
        for (auto& d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if (ni >= 0 && ni < land.size() && nj >= 0 && nj < land[0].size() && land[ni][nj] == 1) {
                dfs(land, ni, nj, maxRow, maxCol);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size();
        int cols = land[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (land[i][j] == 1) {
                    int maxRow = -1;
                    int maxCol = -1;
                    
                    dfs(land, i, j, maxRow, maxCol);
                    
                    ans.push_back({i, j, maxRow, maxCol});
                }
            }
        }
        
        return ans;
    }
};
