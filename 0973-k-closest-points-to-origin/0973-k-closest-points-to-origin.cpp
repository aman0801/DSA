class Solution {
public:
    
    int partition(vector<pair<int, int>>& distances, int low, int high) {
    int pivot = distances[high].first;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (distances[j].first <= pivot) {
            i++;
            swap(distances[i], distances[j]);
        }
    }

    swap(distances[i + 1], distances[high]);
    return i + 1;
}

    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> distances;
        vector<vector<int>> result;
        for (int i = 0; i < points.size(); i++) {
        int distance = pow(points[i][0], 2) + pow(points[i][1], 2);
        distances.push_back({distance, i});
        }
        
         int left = 0;
    int right = distances.size() - 1;
    while (left <= right) {
        int pivotIndex = partition(distances, left, right);
        if (pivotIndex == k - 1) {
            break;
        } else if (pivotIndex > k - 1) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex + 1;
        }
    }

    for (int i = 0; i < k; i++) {
        int index = distances[i].second;
        result.push_back(points[index]);
    }

    return result;
    }
};