class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        unordered_map<char, int>mp;
        
        for(auto& i:tasks){
            mp[i]++;
        }
        
        for(auto& i:mp){
            pq.push(i.second);
        }
        
        int ans = 0;
        
        while(!pq.empty()){
            vector<int>rem;    
            int temp=n+1; 
            
            while(temp>0 && !pq.empty()){
                int freq = pq.top();
                pq.pop();
                if(freq>1){
                     rem.push_back(freq-1);
                }
                ans++;
                temp--;
            }
            
            for(auto& i:rem){
                pq.push(i);
            }
            
            if(pq.empty()){
                break;
            }
            
            ans=ans+temp;
        }
        return ans;
    }
};