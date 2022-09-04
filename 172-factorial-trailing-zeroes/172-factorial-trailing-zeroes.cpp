class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i++){
            int x=i;
            while(x%5==0){
                ans++;
                x/=5;
            }
        }
        return ans;
    }
};