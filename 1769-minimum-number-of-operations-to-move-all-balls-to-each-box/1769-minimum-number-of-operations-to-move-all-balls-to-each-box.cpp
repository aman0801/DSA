class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        // int count = 0;
        
        for(int i=0; i<boxes.size(); i++){
            int count = 0;
            for(int j=0; j<boxes.size(); j++){
                if(boxes[abs(j)] == '1' && i!=j){
                    count = count + abs(i-j);
                }
            }
            // ans[i] = count;
            ans.push_back(count);
        }
        return ans;
    }
};

