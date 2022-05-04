class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        long long ans=0;
        int mod=1e9+7;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                long long x=arr[i]+arr[l]+arr[r];
                if(x==target){
                   int count1=1,count2=1;
                    int j=arr[l];
                    int k=arr[r];
                    while(l<r && arr[l]==arr[l+1]){
                        l++;
                        count1++;
                    }
                    while(l<r && arr[r]==arr[r-1]){
                        r--;
                        count2++;
                    }
                    if(l==r){
                        ans=(ans%mod+((count1%mod)*((count1%mod-1))/2)%mod);
                    }
                    else{
                        ans=((ans%mod)+((count1%mod)*(count2%mod)));
                    }
                    l++;
                    r--;
                }
                else if(x>target){
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
