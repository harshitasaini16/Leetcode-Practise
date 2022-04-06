class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        int mod=1e9+7;
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                long long s=arr[i]+arr[l]+arr[r];
                if(s==target){
                    int count1=1,count2=1;
                    while(l<r && arr[l]==arr[l+1]){
                        l++;
                        count1++;
                    }
                    while(l<r && arr[r]==arr[r-1]){
                        r--;
                        count2++;
                    }
                    if(l==r){
                        ans=(ans%mod+((count1%mod)*((count1-1)%mod))/2)%mod;
                    }
                    else{
                        ans=ans%mod+((count1%mod)*(count2%mod));
                    }
                    l++;
                    r--;
                }
                else if(s>target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};