class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long ans = 0;
        int count = 0;
        vector<int>temp;
        // int count_2 = 0;
        for(int i=0; i<bank.size(); i++){
             count = 0;
            for(int j=0; j<bank[0].size(); j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            if(count>0){
                temp.push_back(count);
        }
            }
        if(temp.size()<=1){  
            return 0;
        }
        //     for(int k=1; k<bank.size(); k++){
        //           count_2 = 0;
        //         for(int l=0; l<k.size(); l++){
        //         if(bank[k][l]!=0){
        //             count_2++;
        //         }
        //     }
        // }
            for(int i=0; i<temp.size()-1; i++){
                ans = ans + (temp[i]*temp[i+1]); 
            }
        
        return ans;
    }
};

