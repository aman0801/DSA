class Solution {
public:
    int minOperations(string s) {
            int count1=0, count2=0;
            for(int i=0; i<s.length(); i++){
                    if(i%2!=s[i]-'0'){
                            count1++;
                    }else{
                            count2++;
                    }
            }
            return min(count1, count2);
    }
};