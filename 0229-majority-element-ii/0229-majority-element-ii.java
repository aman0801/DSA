class Solution {
    public List<Integer> majorityElement(int[] nums) {
            List<Integer> ans = new ArrayList<>();
            int count1 = 0;
            int count2 = 0;
            int ele1 = 0;
            int ele2 = 0;
            
            for(int i=0; i<nums.length; i++){
                    if(count1 == 0 && nums[i]!=ele2){
                            count1++;
                            ele1 = nums[i];
                    }else if(count2 == 0 && nums[i]!=ele1){
                            count2++;
                            ele2 = nums[i];
                    }else if(ele1 == nums[i]){
                            count1++;
                    }else if(ele2 == nums[i]){
                            count2++;
                    }else{
                            count1--;
                            count2--;
                    }
            }
            
            int c1=0,c2=0;
            
            for(int i=0; i<nums.length; i++){
                    if(ele1 == nums[i]){
                            c1++;
                    }else if(ele2 == nums[i]){
                            c2++;
                    }
            }
            
            if(c1>nums.length/3){
                    ans.add(ele1);
            }
            if(c2>nums.length/3){
                    ans.add(ele2);
            }
            return ans;
    }
}