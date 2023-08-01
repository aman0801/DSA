class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        string ans;
        for (int i = 0; i < s.size(); ++i) {
            char maxChar = ' ';
            int maxFreq = 0;
            for (const auto& entry : freq) {
                if (entry.second > maxFreq) {
                    maxChar = entry.first;
                    maxFreq = entry.second;
                }
            }

            ans += string(maxFreq, maxChar);
            freq.erase(maxChar);
        }

        return ans;
    }
};