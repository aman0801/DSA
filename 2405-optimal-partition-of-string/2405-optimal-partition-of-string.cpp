class Solution {
public:
    int partitionString(string s) {
        vector<int>lastSeen(26, -1);
        int count = 0;
        int curr = 0;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(lastSeen[ch - 'a'] >= curr){
                count++;
                curr = i;
            }
            
            lastSeen[ch-'a'] = i;
        }
        return count+1;
    }
};