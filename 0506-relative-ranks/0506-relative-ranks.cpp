class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
            unordered_map<int,int>mp;
            vector<string> ans(score.size());
            for(int i=0; i<score.size(); i++){
                    mp[score[i]] = i;
            }
            sort(score.begin(), score.end(), greater<int>());
            
            for(int i=0; i<score.size(); i++){
                    if(i==0){
                            int tmp = mp[score[i]];
                            ans[tmp] = "Gold Medal";
                    }else if(i==1){
                            int tmp = mp[score[i]];
                            ans[tmp] = "Silver Medal";
                    }else if(i==2){
                            int tmp = mp[score[i]];
                            ans[tmp] = "Bronze Medal";
                    }else{
                            int tmp = mp[score[i]];
                            ans[tmp] = to_string(i+1);
                    }
            }
            return ans;
    }
};