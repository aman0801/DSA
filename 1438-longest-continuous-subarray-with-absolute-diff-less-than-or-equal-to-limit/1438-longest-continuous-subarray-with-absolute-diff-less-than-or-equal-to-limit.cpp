class Solution {
public:
        
    typedef pair<int, int> P;    
        
    int longestSubarray(vector<int>& nums, int limit) {
            priority_queue<P> maxPq;
            priority_queue<P, vector<P>, greater<P>> minPq;
            
            int i=0;
            int j=0;
            int ans=0;
            
            while(i<nums.size()){
                    maxPq.push({nums[i], i});
                    minPq.push({nums[i], i});
                    
                    while(maxPq.top().first - minPq.top().first > limit){
                            j = min(maxPq.top().second, minPq.top().second)+1;
                            
                            while(maxPq.top().second < j){
                                   maxPq.pop(); 
                            }
                            while(minPq.top().second < j){
                                   minPq.pop(); 
                            }
                    }
                    
                    ans = max(ans, i-j+1);
                    i++;
            }
            return ans;
    }
};