class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int ans=0;
    unordered_map<int,int>mp;
    for(int i=0; i<arr.size(); i++)
      {
         mp[arr[i]]++;
      }
    for(auto i:mp)
     {
        if(i.second==1)
     {
        ans= i.first;
     }
  }
     return ans;
     }
};