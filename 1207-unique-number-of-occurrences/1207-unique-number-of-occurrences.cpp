class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
            sort(arr.begin(), arr.end());
            vector<int>vec;
            for(int i=0; i<arr.size(); i++){
                    int cnt = 1;

            while(i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                    cnt++;
                    i++;
            }
                    vec.push_back(cnt);
            }
            sort(vec.begin(), vec.end());
            
            for (int i = 1; i < vec.size(); i++) {
                    if (vec[i] == vec[i - 1]) {
                            return false;
                    }
            }

        return true;
    }
};