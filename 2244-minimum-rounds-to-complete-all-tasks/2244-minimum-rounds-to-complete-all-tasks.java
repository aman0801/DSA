class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer>mp = new HashMap();
        for(int i: tasks){
            mp.put(i, mp.getOrDefault(i, 0)+1);
        }
        int ans = 0;
        
        for(int count: mp.values()){
            if(count == 1)return -1;
            if (count % 3 == 0) {
                ans += count / 3;
            } else {
                ans += count / 3 + 1;
        }
    }
    return ans;
  }
}