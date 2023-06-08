class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    unordered_map<int, int> frequency;
    int count = 0;

    for (const auto& row : grid) {
        for (int num : row) {
            frequency[num]++;
            if (num < 0) {
                count++;
            }
        }
    }

    int negativeCount = 0;
    for (const auto& pair : frequency) {
        if (pair.first < 0) {
            negativeCount += pair.second;
        }
    }

    return negativeCount;
}


};