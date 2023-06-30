class Solution {
public:
    int count = 0;
    
    void swap(vector<int>& arr, int num, int j){
        int temp = arr[j];
        arr[j] = arr[num];
        arr[num] = temp;
    }
    
    void solve(vector<int>& arr, int num){
        if(num == arr.size()){
            count++;
        }
        for(int i=num; i<arr.size(); i++){
            swap(arr, num, i);
            if(arr[num]%(num+1) == 0 || (num+1)%arr[num] == 0){
                solve(arr, num+1);
                // swap(arr, num, i);
            }
            swap(arr, num, i);
        }
    }
    
    int countArrangement(int n) {
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            arr[i] = i+1;
            // cout << arr[i];
        }
        solve(arr, 0);
        return count;
    }
};