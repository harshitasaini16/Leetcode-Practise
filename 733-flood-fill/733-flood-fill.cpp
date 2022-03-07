class Solution {
public:
    void fun(int sr,int sc,vector<vector<int>>&image,int oc,int nc){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=oc || image[sr][sc]==nc){
            return;
        }
        image[sr][sc]=nc;
        fun(sr+1,sc,image,oc,nc);
        fun(sr-1,sc,image,oc,nc);
        fun(sr,sc+1,image,oc,nc);
        fun(sr,sc-1,image,oc,nc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        fun(sr,sc,image,image[sr][sc],newColor);
        return image;
    }
};