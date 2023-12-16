class Solution {
        
     public boolean isEat(int[] piles, int h, int x){
             long total = 0;
             for(int i=0; i<piles.length; i++){
                     total += Math.ceil((double)piles[i] / (double)x);
             }
             return total<=h;
     }   
        
    public int minEatingSpeed(int[] piles, int h) {
            int mini = 1;
            int maxi = Integer.MIN_VALUE;
            
            for(int i=0; i<piles.length; i++){
                    mini = Math.min(piles[i], mini);
                    maxi = Math.max(piles[i], maxi);
            }
            
            while(mini<=maxi){
                    int mid = (mini+maxi)/2;
                    
                    if(isEat(piles, h, mid)){
                            maxi = mid-1;
                    }else{
                            mini = mid+1;
                    }
                    
            }
            return mini;
    }
}