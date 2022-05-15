class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& images) {
        for(int i=0;i<images.size();i++){
            reverse(images[i].begin(),images[i].end());
            for(int j=0;j<images[i].size();j++){
                images[i][j]=!images[i][j];
            }
        }
        return images;
    }
};