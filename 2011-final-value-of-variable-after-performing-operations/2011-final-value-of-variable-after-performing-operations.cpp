class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for(auto i : operations){
            if(i == "++X" or i == "X++"){
                X = X + 1;
            }else if(i == "--X" or i == "X--"){
                X = X - 1;
            }
        }
        return X;
    }
};