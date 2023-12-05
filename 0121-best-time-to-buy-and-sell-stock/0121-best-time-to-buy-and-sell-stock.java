class Solution {
    public int maxProfit(int[] prices) {
            int ans = 0;
            int ele = prices[0];
            
            for(int i=1; i<prices.length; i++){
                    if(ele>prices[i]){
                            ele = prices[i];
                    }else{
                            ans = Math.max(ans, prices[i]-ele);
                    }
            }
            return ans;
    }
}