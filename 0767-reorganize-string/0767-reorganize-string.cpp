class Solution {
public:
    string reorganizeString(string s) {
        //pq<data type,vector<data type>>pq;
        priority_queue<vector<int>,vector<vector<int>>>pq;
        int n=s.size();
        vector<int>chars(26,0);
        for(auto i:s){
            chars[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(chars[i]>(n+1)/2){
                return "";
            }
            pq.push({chars[i],i});
        }
        string ans=s;
        int j=0;
        while(!pq.empty()){
            vector<int>temp=pq.top();
            pq.pop();
            int freq=temp[0];
            char c=(char)('a'+temp[1]);
            for(int i=0;i<freq;i++){
                ans[j]=c;
                j+=2;
                if(j>=n){
                    j=1;
                }
            }
        }
        return ans;
    }
};