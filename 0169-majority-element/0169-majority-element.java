class Solution {
    public int majorityElement(int[] nums) {
            HashMap<Integer, Integer>mp = new HashMap<>();
            
            for(int i:nums){
                    if(!mp.containsKey(i)){
                            mp.put(i, 1);
                    }else{
                            mp.put(i, mp.get(i)+1);
                    }
                    
                    if(mp.get(i)>nums.length/2){
                            return i;
                    }
            }
            return 0;
    }
}