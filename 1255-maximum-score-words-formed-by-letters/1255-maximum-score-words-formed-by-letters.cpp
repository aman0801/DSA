class Solution {
public:
        
    void solve(int idx, vector<int>& score, vector<string>& words, int curr, vector<int>& freq, int& ans){
            ans=max(ans, curr);
            if(idx>=words.size()){
                    return;
            }
            int j=0;
            int tmpScore = 0;
            vector<int> tempFreq = freq;
            while(j<words[idx].length()){
                    char ch = words[idx][j];
                    tempFreq[ch - 'a']--;
                    tmpScore += score[ch - 'a'];
                    if(tempFreq[ch-'a'] < 0)break;
                    
                    j++;
            }
            if(j==words[idx].length()){
                    solve(idx+1, score, words, curr+tmpScore, tempFreq, ans);
            }
            solve(idx+1, score, words, curr, freq, ans);
    }    
        
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
            vector<int> freq(26, 0);
            for(char &ch : letters){
                    freq[ch - 'a']++;
            }
            int ans = INT_MIN;
            solve(0, score, words, 0, freq, ans);
            return ans;
    }
};