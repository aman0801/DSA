class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
            for(int i=0; i<s.size(); i++){
                    if(isalpha(s[i])){
                            count++;
                    }else if(s[i] == ' ' && isalpha(s[i+1])){
                            count = 0;
                    }
            }
            return count;
    }
};