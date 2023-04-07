class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> visited(256, false);
        int first = 0, last = 0, maxi = 0, length = s.length();
        while(last < length) {
            if(!visited[s[last]]) {
                visited[s[last]] = true;
                maxi = max(maxi, last++ - first + 1);
            } else {
                while(visited[s[last]])
                    visited[s[first++]] = false;
                visited[s[last++]] = true;
            }
        }
        return maxi;
    }
};