class Solution {
public:
     int minDeletions(string s) {
        unordered_map<char, int> mp;
        for (auto& i : s) {
            mp[i]++;
        }

        priority_queue<int> pq;
        for (auto& kv : mp) {
            pq.push(kv.second);
        }

        int count = 0;

        while (!pq.empty()) {
            int freq = pq.top();
            pq.pop();

            if(pq.empty()){
                return count;
            }
            
            if(freq == pq.top()){
                count++;
                if(freq>1){
                    pq.push(freq-1);
                }
            }
            
        }

        return count;
    }
};
