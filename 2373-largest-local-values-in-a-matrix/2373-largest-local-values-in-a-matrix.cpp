class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
            vector<vector<int>> ans(grid.size()-2, vector<int>(grid.size()-2, 0));
            for(int i=0; i<grid.size()-2; i++){
                    for(int j=0; j<grid.size()-2; j++){
                            int tmp = INT_MIN;
                            for(int r=i; r<i+3; r++){
                                    for(int c=j; c<j+3; c++){
                                            tmp = max(tmp, grid[r][c]);
                                    }
                            }
                            ans[i][j] = tmp;
                    }
            }
            return ans;
    }
};