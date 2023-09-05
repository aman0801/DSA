class Solution {
public:
    
    void add(vector<vector<string>>& board, vector<vector<string>>& ans, int n) {
    vector<string> out;
    for (int i = 0; i < n; i++) {
        string row = "";
        for (int j = 0; j < n; j++) {
            if (board[i][j] == "Q") {
                row += "Q";
            } else {
                row += ".";
            }
        }
        out.push_back(row);
    }
    ans.push_back(out);
}

    
    bool isSafe(vector<vector<string>>& board, int row, int col, int n){
        int x = row;
        int y = col;
        
//         for same row
        while(y>=0){
            if(board[x][y] == "Q"){
                return false;
            }
            y--;
        }
        
        x = row;
        y = col;
        
//         for same diagonal
        while(x<n && y>=0){
            if(board[x][y] == "Q"){
                return false;
            }
            x++;
            y--;
        }
        
        x = row;
        y = col;
        
//         for same diagonal
        while(x>=0 && y>=0){
            if(board[x][y] == "Q"){
                return false;
            }
            x--;
            y--;
        }
        
        return true;
    }
    
    void solve(int n, vector<vector<string>>& board, vector<vector<string>>& ans, int col){
        if(col == n){
            add(board, ans, n);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = "Q";
                solve(n, board, ans, col+1);
                board[row][col] = ".";
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>board(n, vector<string>(n, "."));
        vector<vector<string>>ans;
        solve(n, board, ans, 0);
        return ans;
    }
};