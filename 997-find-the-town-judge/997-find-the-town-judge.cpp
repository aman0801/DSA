class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
     
        vector<int>data(N+1,0);
        for(auto i : trust){
            data[i[0]]--;
            data[i[1]]++;
        }   
        
        for(int i=1;i<=N;i++){
            if(data[i] == N-1){
                return i;
            }
        }
        return -1;
    }
};