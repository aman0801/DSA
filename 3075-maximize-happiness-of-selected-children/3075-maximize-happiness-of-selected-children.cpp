class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
            priority_queue<int> pq;
            for(auto& it:happiness){
                    pq.push(it);
            }
            long long ans = 0;
            int count=0;
            for(int i=0; i<k; i++){
                    ans = ans + max(pq.top()-count, 0);
                    pq.pop();
                    count++;
            }
            return ans;
    }
};