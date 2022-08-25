class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(auto i:ransomNote){
            map[i]++;
        }
        unordered_map<char,int>map1;
        for(auto j:magazine){
            map1[j]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            
            if(map[ransomNote[i]]>map1[ransomNote[i]])
            return false;
        }
           
        return true;
    }
};