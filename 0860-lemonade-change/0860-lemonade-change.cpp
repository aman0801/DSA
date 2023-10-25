class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        if(bills[0] > 5){
            return false;
        }
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }else if(bills[i] == 10){
                if(five>0){
                    five--;
                    ten++;
                }else{
                    return false;
                }
            }else{
                if((five>0 && ten>0)){
                    five--;
                    ten--;
                }else if(five>=3){
                    five = five - 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};