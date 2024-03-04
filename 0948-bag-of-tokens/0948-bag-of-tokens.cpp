class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
            int ans = 0;
            int i=0;
            int j=tokens.size()-1;
            sort(begin(tokens), end(tokens));
            int tmp=0;
            
            while(i<=j){
                    if(power>=tokens[i]){
                            power = power-tokens[i];
                            tmp++;
                            ans = max(ans, tmp);
                            i++;
                    }else if(tmp>0){
                            power = power + tokens[j];
                            j--;
                            tmp--;
                    }else{
                            return ans;
                    }
            }
            return ans;
    }
};