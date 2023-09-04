class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> store;
        for (int i = 0; i < n; i++) {
            int temp = i + 1;
            store.push_back(temp);
        }

        sort(store.begin(), store.end()); 

        
        while (k > 1 && next_permutation(store.begin(), store.end())) {
            k--;
        }

       
        string result;
        for (int num : store) {
            result += to_string(num);
        }

        return result;
    }
};
