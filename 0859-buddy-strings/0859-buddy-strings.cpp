class Solution {
public:
    
    bool freq(string &s){
        int arr[26] = {0};
        for(auto &i:s){
            arr[i-'a']++;
            
            if(arr[i-'a']>1){
                return true;
            }
        }
        return false;
    }
    
    bool buddyStrings(string s, string goal) {
        if(s == goal){
            return freq(s);
        }
        
        vector<int>check;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=goal[i]){
                check.push_back(i);
            }
        }
        if(check.size()!=2){
            return false;
        }
        // return true;
        swap(s[check[0]], s[check[1]]);
        return s == goal;
    }
};