class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int,int>vis;
        map<int,int>m;
        int n=arr.size();
        if(n==1){
            return 1;
        }
        if(n==2){
            if(arr[1]-arr[0]==diff){
                return 2;
            }
            return 1;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            int x=arr[i]-diff;
            if(vis.find(x)!=vis.end()){
                ans=max(ans,1+m[x]);
                m[arr[i]]=max(m[arr[i]],m[x]+1);
            }
            else{
                m[arr[i]]=1;
            }
            vis[arr[i]]++;
        }
        return ans;
    }
};