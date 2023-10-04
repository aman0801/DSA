class Solution {
public:
    
    bool isPoss(vector<int> &arr, int x,int h){
        long long int total=0;
        for(int i=0;i<arr.size();i++){
            total= total + ceil((double)arr[i]/ (double)x);
        }
        return total<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while(low<=high){
            int mid = (low+high)/2;
            if(isPoss(piles, mid, h)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};