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
       // vector<vector<int>> ans(r,vector<int>(c,0));
      vector<vector<int>> ans;

        vector<int>temp;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp.push_back(mat[i][j]);
                
                y++;
                
               
                if(y==c)
                {   
                    ans.push_back(temp);
                    temp.erase(temp.begin(),temp.end());
                     y=0;
                    // x++;
                }
                   
            }
        }
        
        return ans;
    }
};