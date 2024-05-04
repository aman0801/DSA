class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
            sort(begin(people), end(people));
            int ans=0;
            int i=0;
            int j=people.size()-1;
            int count;
            while(i<=j){
                    // count=2;
                    if(people[i]+people[j]<=limit){
                            ans++;
                            i++;
                            j--;
                    }else if(people[i]+people[j]>limit){
                            if(people[j]<=limit){
                                    ans++;
                                    j--;
                            }
                            
                    }else if((people[i]+people[i+1]<=limit) && i+1<=j){
                                    ans++;
                                    i=i+2;
                    }else{
                            ans++;
                            i++;
                    }
            }
            return ans;
    }
};
/*
[5,1,7,4,2,4]
7
1,2,4,4,5,7
*/