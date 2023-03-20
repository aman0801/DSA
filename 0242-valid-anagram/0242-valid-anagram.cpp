class Solution {
public:
    bool isAnagram(string s, string t) {
        if(size(s)!=size(t)) return false;
       unordered_map<char,int>m;
           for(auto &i:s)m[i]++;
           for(auto &i:t)m[i]--;
        for(auto &i:m)
            if(i.second!=0)
                return false;
        return true;
    }
};