class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int m=mat.size();
        int n=mat[0].size();
        if(m*n!=r*c){
            return mat;
        }
        
        int x=0;
        int y=0;
       vector<vector<int>> ans(r,vector<int>(c,0));
        // vector<int>temp(26,6);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[x][y]=mat[i][j];
                
                y++;
                
               
                if(y==c)
                {
                     y=0;
                    x++;
                }
                   
            }
        }
        
        return ans;
    }
};