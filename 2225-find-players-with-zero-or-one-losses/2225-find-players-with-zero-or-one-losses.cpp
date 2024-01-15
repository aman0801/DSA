class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
            unordered_map<int, int>mp;
            vector<int>zero;
            vector<int>one;
            
            for(int i=0; i<matches.size(); i++){
                    mp[matches[i][1]]++;
            }
            
            for(int i=0; i<matches.size(); i++){
                    int win = matches[i][0];
                    int lose = matches[i][1];
                    
                    if(mp.find(win) == mp.end()){
                            zero.push_back(win);
                            mp[win] = 2;
                    }
                    if(mp[lose] == 1){
                            one.push_back(lose);
                    }
            }
                 sort(one.begin(), one.end());   
                 sort(zero.begin(), zero.end());   
            
            return {zero, one};
    }
};