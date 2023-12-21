class Solution {
public:
    bool rotateString(string s, string goal) {
            if(s.length()!=goal.length()){
                    return false;
            }
            
            for(int i=0; i<s.length(); i++){
                    int j=0;
                    while(j<s.length() && s[(i+j)%s.length()]==goal[j]){
                            j++;
                    } 
                    if(j==s.length()){
                            return true;
                    }
            }
            return false;
    }
};