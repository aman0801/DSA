class Solution {
    public List<List<Integer>> generate(int numRows) {
            List<List<Integer>>ans = new ArrayList<>();
            for(int i=0; i<numRows; i++){
                    List<Integer>temp = new ArrayList<>(i+1);
                    for(int j=0; j<i+1; j++){
                            temp.add(1);
                    }
                    for(int j=1; j<i; j++){
                            temp.set(j, ans.get(i-1).get(j-1)+ans.get(i-1).get(j));
                    }
                    ans.add(temp);
            }
            return ans;
    }
}