class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long ans=LLONG_MAX;
        int n=beans.size();
        long long pre[n];
        pre[0]=beans[0];
        for(int i=1;i<n;i++){
            pre[i]=(long long)(pre[i-1]+beans[i]);
        }
        long long x=0;
        for(int i=0;i<n;i++){
            long long temp=(long long)((long long)x+((long long)(pre[n-1]-pre[i])-(long long)beans[i]*(n-1-i)));
            if(temp<ans){
                ans=temp;
            }
            x+=beans[i];
        }
        return ans;
    }
};