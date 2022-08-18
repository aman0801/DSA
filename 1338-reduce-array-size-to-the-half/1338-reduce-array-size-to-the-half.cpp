class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>ar;
        int count=0;
        int n=arr.size();
        int n1=arr.size();
        for(auto i:arr){
            mp[i]++;
        }
        for(auto i:mp){
            ar.push_back(i.second);
        }
        sort(ar.begin(),ar.end());
        
        for(int i=ar.size()-1;i>=0;i--){
            n=n-ar[i];
            if(n<=n1/2){
                count=count+1;
                break;
            }else{
                count++;
            }
        }
        return count;
    }
};