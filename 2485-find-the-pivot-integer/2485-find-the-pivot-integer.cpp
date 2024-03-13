class Solution {
public:
    int pivotInteger(int n) {
            if (n == 1) return n;
            int i=1;
            int j=n;
            int suml=i;
            int sumr=n;
            
            while(i<j){
                    if(suml<sumr){
                            i++;
                            suml=suml+i;
                            
                    }else{
                            j--;
                            sumr=sumr+j;
                            
                    }
                    if(suml==sumr && i+1==j-1){
                            return i+1;
                    }
            }
            return -1;
    }
};