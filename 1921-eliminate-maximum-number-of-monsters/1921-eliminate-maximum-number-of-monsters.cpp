class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float>arr;
            for(int i=0; i<dist.size(); i++){
                    arr.push_back((float)dist[i]/speed[i]);
            }
            sort(arr.begin(), arr.end());
            int ans = 0;
            for(int i=0; i<arr.size(); i++){
                    if(arr[i]<=i){
                            break;
                    }
                    ans++;
            }
            return ans;
    }
};