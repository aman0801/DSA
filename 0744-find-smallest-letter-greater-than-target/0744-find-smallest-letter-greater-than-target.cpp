class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         char s=letters[0];
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target){
                s=letters[i];
                break;
            }
        }
        return s;
    }
};