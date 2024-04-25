class Solution {
public:
    int longestIdealString(string s, int k) {
            vector<int>arr(26, 0);
            int ans=0;
            for(int i=0; i<s.length(); i++){
                    int curr=s[i]-'a';
                    int left=max(0, curr-k);
                    int right=min(25, curr+k);
                    
                    int tmp=0;
                    for(int j=left; j<=right; j++){
                            tmp=max(tmp, arr[j]);
                    }
                    arr[curr]=max(arr[curr], tmp+1);
                    ans=max(ans, arr[curr]);
            }
            return ans;
    }
};