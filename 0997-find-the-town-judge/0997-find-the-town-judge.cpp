class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         // unordered_map<int,vector<int>> adj;
        if(trust.empty() && n==1)
            return 1;
        vector<int>InD(n+1, 0);
        vector<int>OutD(n+1, 0);
        
        for(auto i:trust){
            InD[i[1]]++;
            OutD[i[0]]++;
        }
        
        for(int i=0;i<=n;i++){
            if(OutD[i]==0 && InD[i]==n-1)
                return i;
        }
        return -1;
    }
};

