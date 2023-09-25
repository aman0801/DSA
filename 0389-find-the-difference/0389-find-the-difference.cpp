class Solution {
public:
    char findTheDifference(string s, string t) {
         unordered_map<char, int> cnt;

       
        for (char x:t) cnt[x]++;

    
        for (char x:s) cnt[x]--;
        
      
        for (auto x:cnt) if (x.second) return x.first;

   
        return 'a';
    }
};