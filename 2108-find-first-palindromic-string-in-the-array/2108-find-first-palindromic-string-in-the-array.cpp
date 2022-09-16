class Solution {
public:
    
    bool Palindrome(string str){
        int i=0;
        int j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    
    
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(Palindrome(words[i])){
             return words[i];
            }
        }
        return "";
    }
};