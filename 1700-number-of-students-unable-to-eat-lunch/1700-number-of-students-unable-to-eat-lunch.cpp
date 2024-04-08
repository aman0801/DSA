class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
            int zero=0;
            int one=0;
            for(int i=0; i<students.size(); i++){
                    if(students[i]==0){
                            zero++;
                    }else{
                            one++;
                    }
            }
            
            for(int i=0; i<sandwiches.size(); i++){
                    if(sandwiches[i]==0 && zero>0){
                            zero--;
                    }else if(sandwiches[i]==1 && one>0){
                            one--;
                    }else{
                            if(one>0){
                                    return one;
                            }else{
                                    return zero;
                            }
                    }
            }
            return 0;
    }
};