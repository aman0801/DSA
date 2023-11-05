class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = INT_MIN;
            for(int i=0; i<arr.size(); i++){
                    maxi = max(arr[i], maxi);
            }
            
            int count=0, curr=arr[0];
            for(int i=1; i<arr.size(); i++){
                    int opp = arr[i];
                    if(curr>opp){
                            count++;
                    }else{
                            count=1;
                            curr = opp;
                    }
                    if(count == k || maxi == curr){
                            return curr;
                    }
            }
            return -1;
    }
};