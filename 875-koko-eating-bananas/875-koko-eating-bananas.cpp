class Solution {
public:
    bool valid(vector<int>& piles, int& h,int curr){
        int count=0;
        for(auto i:piles){
            count+= i/curr + ((i%curr)!=0); 
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=0;
        for(int i:piles){
            maxi=max(i,maxi);
        }
        int start=1;
        int end=maxi;
        while(start<end){
            //cout<<start<<" "<<end<<endl;
            
            int mid=(start+end)/2;
            if(valid(piles,h,mid)){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return end;
        
    }
};