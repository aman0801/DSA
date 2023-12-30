class Solution {
public:
    bool makeEqual(vector<string>& words) {
            vector<int> arr(26, 0);
            for(auto& i:words){
                    for(auto& j:i){
                            arr[j-'a']++;
                    }
            }
            
            for(auto& i:arr){
                    if(i%words.size()!=0){
                            return 0;
                    }
            }
            return 1;
    }
};