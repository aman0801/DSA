class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        int i = 0;
        int row = 0;
        vector<string>zig(numRows);
        bool direction = 1;
        
        while(true){
            if(direction){
                while(row<numRows && i<s.size()){
                    zig[row++].push_back(s[i++]);
                }
                row = numRows-2;
            }else{
                while(row>=0 && i<s.size()){
                    zig[row--].push_back(s[i++]);
                }
                row = 1;
            }
            if(i>=s.size()){
                break;
            }
            direction=!direction;
        }
        string ans = "";
        for(int i=0; i<zig.size(); i++){
            ans = ans + zig[i];
        }
        return ans;
    }
};