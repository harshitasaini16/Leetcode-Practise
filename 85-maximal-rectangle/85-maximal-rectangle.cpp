class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        vector<int>l(n),r(n);
        l[0]=a[0];
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()){
                l[i]=-1;
            }
            else{
                l[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()){
                r[i]=n;
            }
            else{
                r[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int left=(l[i]+1);
            int right=(r[i]-1);
            int x=right-left+1;
            ans=max(ans,a[i]*x);
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
                    dp[j]+=1;
                }
                else{
                    dp[j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(dp));
        }
        return ans;
    }
};