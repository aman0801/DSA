class Solution {
public:
    int countTriplets(vector<int>& arr) {
            int count=0;
            int a=0;
            int b=0;
            for(int i=0; i<arr.size(); i++){
                    a=0;
                    for(int j=i+1; j<arr.size(); j++){
                            a=a^arr[j-1];
                            b=0;
                            for(int k=j; k<arr.size(); k++){
                                    b=b^arr[k];
                                    if(a==b){
                                            count++;
                                    }
                            }
                    }
            }
            return count;
    }
};