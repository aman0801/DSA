class Solution {
public:
    int reverse(int x) {
            int sign = 1;
            if(x<0){
                    sign = -1;
            }
        string temp = to_string(x);
            string rev = string(temp.rbegin(), temp.rend());
            long long ans = stoll(rev);
            ans = ans*sign;
            if(ans > INT_MAX || ans < INT_MIN){
                    return 0;
            }
            return (int)ans;
    }
};