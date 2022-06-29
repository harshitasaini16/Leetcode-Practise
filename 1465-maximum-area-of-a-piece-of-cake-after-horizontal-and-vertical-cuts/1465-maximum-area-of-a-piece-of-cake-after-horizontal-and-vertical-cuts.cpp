class Solution {
public:
    int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ver) {
        sort(ho.begin(),ho.end());
        sort(ver.begin(),ver.end());
        int x=ho[0];
        int y=ver[0];
        int n=ho.size();
        int m=ver.size();
        for(int i=1;i<ho.size();i++){
            x=max(x,abs(ho[i]-ho[i-1]));
        }
        for(int i=1;i<ver.size();i++){
            y=max(y,abs(ver[i]-ver[i-1]));
        }
        x=max(x,h-ho[n-1]);
        y=max(y,w-ver[m-1]);
        // cout<<x<<' '<<y<<endl;
        return ((long long)x*y)%mod;
    }
};