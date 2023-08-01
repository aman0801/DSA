class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        string ans;
        while (!freq.empty()) {
            char maxChar = ' ';
            int maxFreq = 0;
            for (auto it = freq.begin(); it != freq.end(); ++it) {
                if (it->second > maxFreq) {
                    maxChar = it->first;
                    maxFreq = it->second;
                }
            }

            ans += string(maxFreq, maxChar);
            freq.erase(maxChar);
        }

        return ans;
    }
};