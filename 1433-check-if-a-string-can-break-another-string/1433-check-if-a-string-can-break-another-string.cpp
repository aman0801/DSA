class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int ts=s1.length();
        int cnt2=0,cnt1=0;

        for(int i=0;i<ts;i++){
          if(s1[i]>s2[i]){
              cnt1++;
          }
          else if(s2[i]>s1[i]){
              cnt2++;
          }
          else{
              cnt1++;
              cnt2++;
          }
        }
        return cnt1==ts or cnt2==ts?true:false;
    }
};