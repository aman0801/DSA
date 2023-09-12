class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        unordered_set<int>st;
        for(auto& i:s){
            freq[i-'a']++;
        }
        
        int count = 0;
        for(int i=0; i<26; i++){
            while(freq[i]>0 && st.find(freq[i])!=st.end()){
                freq[i] = freq[i]-1;
                count++;
            }
            st.insert(freq[i]);
        }
        return count;
    }
};