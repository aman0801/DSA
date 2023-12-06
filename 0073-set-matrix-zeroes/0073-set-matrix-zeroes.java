class Solution {
    public void setZeroes(int[][] matrix) {
            ArrayList<Integer>x = new ArrayList<>();
            ArrayList<Integer>y = new ArrayList<>();
            
            for(int i=0; i<matrix.length; i++){
                    for(int j=0; j<matrix[0].length; j++){
                            if(matrix[i][j] == 0){
                                    x.add(i);
                                    y.add(j);
                            }
                    }
            }
            
//             for rows
            for(int i=0; i<x.size(); i++){
                    int idx = x.get(i);
                    for(int j=0; j<matrix[0].length; j++){
                            matrix[idx][j] = 0; 
                    }
            }
//             for col
            for(int i=0; i<y.size(); i++){
                    int idx = y.get(i);
                    for(int j=0; j<matrix.length; j++){
                            matrix[j][idx] = 0;
                    }
            }
    }
}