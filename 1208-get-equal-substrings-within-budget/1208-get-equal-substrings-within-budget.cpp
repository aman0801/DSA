class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
            int i=0;
            int j=0;
            int ans=0;
            int sum=0;
            while(i<s.length()){
                    sum = sum + abs((s[i]-'0')-(t[i]-'0'));
                    while(sum > maxCost){
                            sum = sum - abs((s[j]-'0')-(t[j]-'0'));
                            j++;
                    }
                    ans = max(ans, i-j+1);
                    i++;
            }
            return ans;
    }
};