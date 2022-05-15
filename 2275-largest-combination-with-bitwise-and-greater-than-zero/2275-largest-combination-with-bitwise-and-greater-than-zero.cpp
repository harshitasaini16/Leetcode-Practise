class Solution {
public:
    int largestCombination(vector<int>& can) {
        int n=can.size();
        int ans=0;
        for(int i=30;i>=0;i--){
            int c=0;
            for(int j=0;j<n;j++){
                if((can[j]>>i&1)==1){
                    c++;
                }
            }
            ans=max(ans,c);
        }
        return ans;
    }
};