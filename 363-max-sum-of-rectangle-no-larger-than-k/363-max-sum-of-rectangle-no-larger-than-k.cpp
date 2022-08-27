class Solution {
public:
     int maxSumArray(int a[],int k,int n)
    {
        set<int>s;
        int sum=0,ansMax=-1e6;
        for(int i=0;i<n;i++) 
        {
            sum+=a[i];
            if(sum<=k) ansMax=max(ansMax,sum);
            if(s.size()>0)
            {
                int temp=sum-k;
                auto it=s.lower_bound(temp);
                if(it!=s.end() && sum-*it<=k )
                ansMax=max(ansMax,sum- *it );
            }
            s.insert(sum);
        }
        return ansMax;
    }
    int maxSumSubmatrix(vector<vector<int>>& v, int k) {
        int n=v.size(),m=v[0].size(),finalMaxSum=-1e6;
        for(int i=0;i<n;i++)
        {
            int a[m];
            memset(a,0,sizeof(a));
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++) a[k]+=v[j][k];
                int ans=maxSumArray(a,k,m);
                finalMaxSum=max(finalMaxSum,ans);
            }
        }
        return finalMaxSum;
    }
};