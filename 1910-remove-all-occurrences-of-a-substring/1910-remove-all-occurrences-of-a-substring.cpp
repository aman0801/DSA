class Solution {
public:
    
    void remove(string &s, string &part){
        int find = s.find(part);
        if(find!=string::npos){
            string l = s.substr(0, find);
            string r = s.substr(find+part.size(), s.size());
            s = l+r;
            remove(s, part);
        }else{
            return;
        }
    }
    
    string removeOccurrences(string s, string part) {
        remove(s, part);
        return s;
    }
};