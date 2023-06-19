class Solution {
public:
    
    vector<int> right(vector<int>& heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());
        for(int i=heights.size()-1; i>=0; i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> left(vector<int>& heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());
        for(int i=0; i<heights.size(); i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>leftarr = left(heights);
        vector<int>rightarr = right(heights);
        
        int ans = INT_MIN;
        int size = heights.size();
        for(int i=0; i<heights.size(); i++){
            int l = heights[i];
            if(rightarr[i] == -1){
                rightarr[i] = size;
            }
            int w = rightarr[i] - leftarr[i] - 1;
            int area = l*w;
            ans = max(ans, area);
        }
        return ans;
    }
};