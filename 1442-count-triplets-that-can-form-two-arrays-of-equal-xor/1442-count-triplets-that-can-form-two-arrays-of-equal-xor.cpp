class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int prefix[n+1];
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]^arr[i-1];
        }
        int ans=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=i;k<=n;k++){
                    int pre1=prefix[i-1]^prefix[j-1];
                    int pre2=prefix[k]^prefix[i-1];
                    if(pre1==pre2){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};