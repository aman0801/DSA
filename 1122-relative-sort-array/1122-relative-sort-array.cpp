class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
            vector<int>ans;
            map<int, int>mp;
            for(auto& it:arr1){
                    mp[it]++;
            }
            for(int i=0; i<arr2.size(); i++){
                    int tmp = mp[arr2[i]];
                    for(int j=0; j<tmp; j++){
                            ans.push_back(arr2[i]);
                    }
                    mp[arr2[i]] = 0;
            }
            for(auto& it:mp){
                    if(it.second>0){
                            int tempp = it.second;
                            while(tempp>0){
                                    ans.push_back(it.first);
                                    tempp--;
                            }
                    }
            }
            return ans;
    }
};