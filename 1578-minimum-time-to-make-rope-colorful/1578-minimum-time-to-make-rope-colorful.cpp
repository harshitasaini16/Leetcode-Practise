class Solution {
public:
    int minCost(string colors, vector<int>&time) {
        int n=time.size();
        if(n==1){
            return 0;
        }
        int x=1;
        int ans=0;
        int s=time[0];
        int mx=time[0];
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                x++;
                mx=max(mx,time[i]);
                s+=time[i];
            }
            else if(colors[i]!=colors[i-1]){
                s-=mx;
                ans+=s;
                s=time[i];
                mx=time[i];
            }
        }
        if(colors[n-1]==colors[n-2]){
            s-=mx;
            ans+=s;
        }
        return ans;
    }
};