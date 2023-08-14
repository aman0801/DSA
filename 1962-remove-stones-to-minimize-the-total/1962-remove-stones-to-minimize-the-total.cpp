class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
            
            for(auto &i:piles){
                    pq.push(i);
            }
            
            while(k--){
                    int temp = pq.top(); pq.pop();
                    temp = temp - temp/2;
                    cout << temp << endl;
                    pq.push(temp);
            }
            int sum = 0;
            while(!pq.empty()){
                    sum = sum + pq.top();
                    pq.pop();
            }
            return sum;
    }
};