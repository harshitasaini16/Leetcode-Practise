class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int k=(i+1)*(n-i);
            if(k%2==0){
                k/=2;
            }
            else{
                k/=2;
                k++;
            }
            ans+=(k*arr[i]);
        }
        return ans;
    }
};