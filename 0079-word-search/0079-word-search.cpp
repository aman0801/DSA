class Solution {
public:
    bool search(vector<vector<char>>&board, string word, int i, int j, int index){
        
        if(index == word.size()) return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j] != word[index])
            return false;
        // index++;
        // if(board[i][j] != word[index])return false;
        board[i][j] = '*';
        
        bool find = search(board, word, i+1, j, index+1) or
                    search(board, word, i-1, j, index+1) or
                    search(board, word, i, j-1, index+1) or
                    search(board, word, i, j+1, index+1);
        
        board[i][j] = word[index]; 
       return find;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0] and search(board, word, i, j, 0))return true;
            }
        }
        return false;
    }
};

