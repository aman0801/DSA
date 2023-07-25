class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        int mid = (s+e)/2;
        int ans;
        while(s<e){
                mid = (s+e)/2;
                if(arr[mid]<arr[mid+1]){
                        s = mid+1;
                }else{
                        e = mid;
                }
        }
            return s;
    }
};