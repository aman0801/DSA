class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        vector<int>ans;
        while(left < right){
            int mid = (left + right)/2;
            if(x - arr[mid] > arr[mid+k] - x){
                left = mid +1;
            }else{
                right = mid;
            }
        }
        for(int i =0;i < k;i++){
            ans.push_back(arr[left + i]);
        }
        return ans;
    }
};
