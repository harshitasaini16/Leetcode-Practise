class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        int n=beans.size();
        long long pre[n];
        pre[0]=0;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+beans[i-1];
        }
        long long s=0;
        long long ans=LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            long long x=(s-((long long)beans[i]*(n-i-1))+pre[i]);
            ans=min(ans,x);
            s+=beans[i];
        }
        return ans;
    }
};
