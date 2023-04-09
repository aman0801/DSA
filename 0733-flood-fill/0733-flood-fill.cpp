class Solution {
public:
    
     void fun(vector<vector<int>>&image ,int sr, int sc, int newColor,
             int oldColour)
    {
        int m = image.size();
        int n = image[0].size();

        if(sr<0 || sc<0 || sr>=m || sc >=n || image[sr][sc]!=oldColour) return;
        
        image[sr][sc] = newColor;
 
        
        fun(image,sr-1,sc,newColor,oldColour);
        fun(image,sr+1,sc,newColor,oldColour);
        fun(image,sr,sc-1,newColor,oldColour);
        fun(image,sr,sc+1,newColor,oldColour);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor==color)
            return image;
        fun(image,sr,sc,color,oldColor);
        return image;
    }
};