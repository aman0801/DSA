class Solution {
public:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};    
    int solve(vector<vector<int>>& grid, int i, int j){
            if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
                    return 0;
            }
            int og = grid[i][j];
            grid[i][j] = 0;
            int tmp=0;
            for(auto& it:dir){
                    int _i = i+it[0];
                    int _y = j+it[1];
                    
                    tmp = max(tmp, solve(grid, _i, _y));
            }
            grid[i][j] = og;
            return tmp+og;
    }    
        
    int getMaximumGold(vector<vector<int>>& grid) {
            int ans = 0;
            for(int i=0; i<grid.size(); i++){
                    for(int j=0; j<grid[0].size(); j++){
                            if(grid[i][j]!=0){
                                    ans = max(ans, solve(grid, i, j));
                            }
                    }
            }
            return ans;
    }
};