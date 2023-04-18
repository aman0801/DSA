class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0;
        while(i<word1.size() && j<word2.size())
        {
            ans = ans + word1[i];
            i++;
            ans = ans + word2[j];
            j++;
        }
        while(i<word1.size())
        {
            ans = ans + word1[i];
            i++;
        }
         while(j<word2.size())
        {
            ans = ans + word2[j];
             j++;
        }
        return ans;
    }
};