class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<pair<int,int>,int>m;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int x=points[i][0]-points[j][0];
                    int y=points[i][1]-points[j][1];
                    int g=__gcd(x,y);
                    x/=g;
                    y/=g;
                    m[{x,y}]++;
                }
            }
            for(auto x:m){
                ans=max(ans,x.second);
            }
        }
        return ans+1;
    }
};