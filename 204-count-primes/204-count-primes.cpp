class Solution {
public:
    int countPrimes(int n) {
        vector<int>dp(n,0);
        if(n<3){
            return 0;
        }
        int ans=1;
        for(int i=3;i<n;i+=2){
            if(dp[i]==0){
                ans++;
                if(i>sqrt(n)){
                    continue;
                }
                int j=i*i;
                while(j<n){
                    dp[j]=1;
                    j=j+i;
                }
            }
        }
        return ans;
    }
};