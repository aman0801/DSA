class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        string a = "";
        
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            while(i < s.size() and !isVowel(s[i])){
                i++;
            }
            while(j >=0 and !isVowel(s[j])){
                j--;
            }
            if(i<j){
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};