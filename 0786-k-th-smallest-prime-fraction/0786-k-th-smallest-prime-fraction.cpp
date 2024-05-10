class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
            priority_queue<vector<double>> pq;
            for(int i=0; i<arr.size(); i++){
                    for(int j=i+1; j<arr.size(); j++){
                            double frac = (double) arr[i] / arr[j];
                            pq.push({frac, (double) arr[i], (double) arr[j]});
                            while(pq.size()>k){
                                    pq.pop();
                            }
                    }
            }
            auto tmp = pq.top();
            return {(int)tmp[1], (int)tmp[2]};
    }
};