class Solution {
public:
    
    static bool com(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1>t2;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string>temp;
        
        for(auto n : nums){
            temp.push_back(to_string(n));
        }
        sort(temp.begin(), temp.end(), com);
        
        if(temp[0] == "0")return "0";
        
        for(auto i : temp){
            ans = ans + i;
        }
        return ans;
    }
};