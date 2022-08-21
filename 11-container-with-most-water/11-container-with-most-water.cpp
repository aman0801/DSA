class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area=0;
        while(i<j){
            int area2=0;
           if(height[i]<height[j]){
               area2=height[i]*(j-i);
               i++;
           }else{
               area2=height[j]*(j-i);
               j--;
           }
            if(area<=area2){
                area=area2;
            }
        }
        return area;
    }
};