class Solution {
public:
    string reversePrefix(string word, char ch) {
            int chIndex = word.find(ch);
            if (chIndex == -1) {
                    return word;
            }
            
            string result;
            for (int i = 0; i < word.length(); i++) {
                    if (i <= chIndex) {
                            result += word[chIndex - i];
                    }else {
                            result += word[i];
                    }
            }
            return result;
    }
};