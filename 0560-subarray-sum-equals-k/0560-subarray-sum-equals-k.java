class Solution {
    public int subarraySum(int[] nums, int k) {
            HashMap<Integer, Integer>mp = new HashMap<>();
            int count=0;
            int sum=0;
            for(int i=0; i<nums.length; i++){
                    sum = sum + nums[i];
                    if(sum == k){
                            count++;
                    }
                    
                    if(mp.containsKey(sum-k)){
                            count = count + mp.get(sum-k);
                    }
                    
                    mp.put(sum, mp.getOrDefault(sum, 0) + 1);
            }
            return count;
    }
}