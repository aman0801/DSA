class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //Method -1 --sorting
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        return s==t;
        
        
        
    }
};