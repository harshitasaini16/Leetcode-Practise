class Solution {
public:
    int fun(vector<int>dp,int n){
        int left[n],right[n];
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && dp[s.top()]>=dp[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }
            else{
                left[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && dp[s.top()]>=dp[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }
            else{
                right[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=left[i]+1;
            int r=right[i]-1;
            ans=max(ans,(r-l+1)*dp[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>dp(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                    dp[j]++;
                }
                else{
                    dp[j]=0;
                }
            }
            ans=max(ans,fun(dp,m));
        }
        return ans;
    }
};