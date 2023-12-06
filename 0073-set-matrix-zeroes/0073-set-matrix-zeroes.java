class Solution {
        
    public void solve(int i, int j, int[][] temp, int n, int m){
            for(int col=0; col<m; col++){
                    temp[i][col]=0;
            }
            for(int row=0; row<n; row++){
                    temp[row][j]=0;
            }
    }    
        
    public void setZeroes(int[][] matrix) {
            int m = matrix[0].length;
            int n = matrix.length;
            
            int temp[][] = new int[n][m];
            
            for (int i = 0; i < n; i++) {
            System.arraycopy(matrix[i], 0, temp[i], 0, m);
        }
            
            for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                            if(matrix[i][j] == 0){
                                    solve(i, j, temp, n, m);
                            }
                    }
            }
             for (int i = 0; i < n; i++) {
            System.arraycopy(temp[i], 0, matrix[i], 0, m);
        }
    }
}