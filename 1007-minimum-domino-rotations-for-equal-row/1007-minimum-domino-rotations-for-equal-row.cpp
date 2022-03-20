class Solution {
public:
    int fun(vector<int>&tops, vector<int>&bottoms,int x,int n){
        if(n==0){
            return 0;
        }
        if(tops[n-1]==x){
            return fun(tops,bottoms,x,n-1);
        }
        else if(bottoms[n-1]==x){
            int y=fun(tops,bottoms,x,n-1);
            if(y==INT_MAX){
                return INT_MAX;
            }
            return 1+y;
        }
        else{
            return INT_MAX;
        }
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            ans=min(ans,fun(tops,bottoms,i,tops.size()));
            ans=min(ans,fun(bottoms,tops,i,tops.size()));
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};