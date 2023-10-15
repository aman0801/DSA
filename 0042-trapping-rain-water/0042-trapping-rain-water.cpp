class Solution {
public:
    
    vector<int>solveLeft(vector<int>& height){
        vector<int>ans(height.size());
        ans[0] = height[0];
        
        for(int i=1; i<height.size(); i++){
            ans[i] = max(ans[i-1], height[i]);
        }
        return ans;
    }
    
    vector<int>solveRight(vector<int>& height){
        vector<int>ans(height.size());
        ans[height.size()-1] = height[height.size()-1];
        
        for(int i=height.size()-2; i>=0; i--){
            ans[i] = max(ans[i+1], height[i]);
        }
        return ans;
    }
    
    int trap(vector<int>& height) {
        vector<int>left = solveLeft(height);
        vector<int>right = solveRight(height);
        int sum = 0;
        for(int i=0; i<height.size(); i++){
            int h = min(left[i], right[i])-height[i];
            sum = sum+h;
        }
        return sum;
    }
};