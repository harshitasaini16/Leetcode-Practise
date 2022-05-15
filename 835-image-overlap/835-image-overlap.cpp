class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>v1,v2;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1[0].size();j++){
                if(img1[i][j]==1){
                    v1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    v2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int>m;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                m[{v1[i].first-v2[j].first,v1[i].second-v2[j].second}]++;
            }
        }
        int ans=0;
        for(auto i:m){
            ans=max(ans,i.second);
        }
        return ans;
    }
};