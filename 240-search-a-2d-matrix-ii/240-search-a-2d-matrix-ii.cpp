class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<vector<int>>mat;
       int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                return true;
            }if(matrix[i][j] < target)
         i++;
     else
         j--;
        }
        return false;
    }
};