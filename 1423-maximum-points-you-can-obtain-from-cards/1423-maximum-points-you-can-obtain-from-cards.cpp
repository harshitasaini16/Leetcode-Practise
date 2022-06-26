class Solution {
public:
    int maxScore(vector<int>&v, int k) {
        int s=0;
        for(int i=0;i<k;i++){
            s+=v[i];
        }
        int ans=s;
        int i=k-1;
        int j=v.size()-1;
        while(k--){
            s+=v[j];
            s-=v[i];
            i--;
            j--;
            ans=max(ans,s);
        }
        return ans;
    }
};