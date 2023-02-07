class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int>mp;
        int i=0,j=0;
        int ans = 0;
        while(i<fruits.size()){
            mp[fruits[i]]++;
            while(j<fruits.size() && mp.size()>2){
                if(mp[fruits[j]] == 1){
                    mp.erase(fruits[j]);
                }else{
                    mp[fruits[j]]--;
                }
                j++;
            }
            ans = max(i-j+1, ans);
            i++;
        }
        return ans;
    }
};