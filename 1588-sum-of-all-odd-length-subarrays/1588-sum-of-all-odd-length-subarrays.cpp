class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int pre[n+1];
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+arr[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if((i-j)%2!=0){
                    int s=pre[i]-pre[j];
                    ans+=s;
                }
            }
        }
        return ans;
    }
};