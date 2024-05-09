class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
            sort(happiness.begin(), happiness.end());
            long long ans=0;
            int i=happiness.size()-1;
            int count = 0;
            while(i>=0 && k>0){
                    if(happiness[i]-count<0){
                            break;
                    }else{
                            if(i==happiness.size()-1){
                                    ans = ans + happiness[i];
                                    cout << ans << "first";
                            }else{
                                    if(happiness[i]-1>0){
                                            ans = ans + happiness[i] - count;
                                            cout << ans << "second";
                                    }else{
                                            break;
                                    }
                            }
                    }
                    k--;
                    i--;
                    count++;
            }
            return ans;
    }
};