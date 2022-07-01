class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& arr, int s) {
        sort(arr.begin(),arr.end(),cmp);
        long long ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int mn=min(arr[i][0],s);
            ans+=(mn*arr[i][1]);
            s-=mn;
            if(s==0){
                return ans;
            }
        }
        return ans;
    }
};