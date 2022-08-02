class Solution {
public:
    int firstUniqChar(string s) {
        int a=-1;
        for(int i=0;i<s.size();i++){
        int flag=0;
            for(int j=0;j<s.size();j++){
               
                
              
             
                if(s[i]==s[j] and i!=j)
                {   
                    flag++;
                    j=s.size()+3;
                    // break;
                }
                
                
            }
            
            if(!flag)
                return i;
            
      
        }
        return -1;
    }
};