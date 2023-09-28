class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        
        
        for (int col = 0; col < cols; col++) {
            vector<int>temp;
            for (int row = 0; row < rows; row++) {
                temp.push_back(matrix[row][col]);
            }
            reverse(temp.begin(), temp.end());
            for(int row=0; row<rows; row++){
                ans[col][row] = temp[row];
            }
        }
        matrix = ans;
    }
};