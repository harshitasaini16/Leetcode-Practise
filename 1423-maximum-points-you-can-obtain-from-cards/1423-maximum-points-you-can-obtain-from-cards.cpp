class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int s=0;
        for(int i=0;i<k;i++){
            s+=c[i];
        }
        int ans=s;
        int x=k-1;
        int y=c.size()-1;
        while(k--){
            s-=c[x];
            s+=c[y];
            x--;
            y--;
            ans=max(ans,s);
        }
        return ans;
    }
};