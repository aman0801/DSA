class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>arr(ratings.size(), 1);
        
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i-1] < ratings[i]){
                arr[i] = arr[i-1]+1;
                // cout << arr[i-1] << endl << i-1 << endl;
            }
        }
        
        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i+1] < ratings[i]){
                arr[i] = max(arr[i+1]+1, arr[i]);
                // cout << arr[i+1] << endl << i+1 << endl;
            }
        }
        
        int sum = 0;
        for(auto& i:arr){
            sum = sum + i;
        }
        return sum;
    }
};