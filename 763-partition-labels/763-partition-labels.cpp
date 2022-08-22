class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            mp[ch]=i; //we put last index of the given alphabets 
        }
        vector<int>ans;
        int prev=-1;
        int Max=0;
        
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            Max=max(Max,mp[s[i]]);
            if(Max==i){
                ans.push_back(Max-prev);
                prev=Max;
            }
        }
        return ans;
    }
};