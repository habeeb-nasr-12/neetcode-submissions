class Solution {
public:
  void dfs(vector<vector<int>>& image , int orgColor , int newColor ,int sr ,int sc ){
   if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != orgColor)
     return;

    image[sr][sc] =newColor;
    dfs(image,orgColor,newColor,sr + 1  ,sc );
    dfs(image,orgColor,newColor,sr  ,sc+1 );
    dfs(image,orgColor,newColor,sr -1, sc );
    dfs(image,orgColor,newColor,sr  , sc -1 );
 
    
}


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        if(orgColor==color)
             return image; 

        dfs(image,orgColor,color ,sr ,sc);

        return image;
    }
};