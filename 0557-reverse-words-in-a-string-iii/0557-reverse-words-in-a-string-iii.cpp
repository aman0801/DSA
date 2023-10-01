class Solution {
public:
    string reverseWords(string s) {
    string ans;
    string temp;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            temp = temp + s[i];
        } else {
            reverse(temp.begin(), temp.end());
            ans = ans + temp + ' ';
            temp = ""; 
        }
    }
    reverse(temp.begin(), temp.end());
    ans = ans + temp; 
    return ans;
}

};