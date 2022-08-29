class Solution {
public:
    bool static cmp(vector<int>v1,vector<int>v2){
        return v1[1]<v2[1];
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>>v;
        int n=s.size();
        for(int i=0;i<n;i++){
            v.push_back({s[i],e[i],p[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int dp[n];
        dp[0]=v[0][2];
        for(int i=1;i<n;i++){
            int s=v[i][2];
            int l=0;
            int r=i-1;
            int last=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(v[mid][1]<=v[i][0]){
                    last=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(last!=-1){
                s+=dp[last];
            }
            int q=dp[i-1];
            dp[i]=max(s,q);
        }
        return dp[n-1];
    }
};