class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            int mx=INT_MIN;
            int x=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    if(arr[j]>mx){
                        mx=arr[j];
                        x=j;
                    }
                }
            }
            if(mx!=INT_MIN){
                swap(arr[i],arr[x]);
                return arr;
            }
        }
        return arr;
    }
};