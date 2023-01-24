class Solution {
public:
    int n;
    pair<int, int> getCord(int num){
        int RT = (num - 1)/n;
        int RB = (n - 1) - RT;
        
        int col = (num - 1) % n;
        if((n%2 == 1 && RB%2 == 1) || (n%2 == 0 && RB%2 == 0))
            col = (n - 1) - col;
        
        return make_pair(RB, col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int count = 0;
         n = board.size();
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        queue<int>q;
        vis[n-1][0] = true;
        
        q.push(1);
        
        while(!q.empty()){
            int N = q.size();
            
            while(N--){
                int x = q.front();
                q.pop();
                
                if(x == n*n){
                    return count;
                }
                for(int k=1; k<=6; k++){
                    int val = k + x;
                    
                    if(val > n*n){
                        break;
                    }
                    pair<int, int>coord = getCord(val);
                    
                    int r = coord.first;
                    int c = coord.second;
                    
                    if(vis[r][c] == true)continue;
                    
                    vis[r][c] = true;
                    
                    if(board[r][c] == -1){
                        q.push(val);
                    }else{
                        q.push(board[r][c]);
                    }
                }
            }
            count++;
        }
        return -1;
        
    }
};