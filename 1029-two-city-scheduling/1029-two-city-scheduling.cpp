class Solution {
public:
    bool static cmp(vector<int>arr,vector<int>brr){
        return arr[1]-arr[0]>brr[1]-brr[0];
    }
    int twoCitySchedCost(vector<vector<int>>& arr) {
        int n=arr.size();
        int ans=0;
        sort(arr.begin(),arr.end(),cmp);
        for(int i=0;i<n/2;i++){
            ans+=arr[i][0];
        }
        for(int i=n/2;i<n;i++){
            ans+=arr[i][1];
        }
        return ans;
    }
};