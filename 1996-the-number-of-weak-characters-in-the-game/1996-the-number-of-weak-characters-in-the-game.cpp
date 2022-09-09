class Solution {
public:
    bool static cmp(vector<int>&v1,vector<int>&v2){
        if(v1[0]<v2[0]){
            return true;
        }
        if(v1[0]==v2[0]){
            if(v1[1]>v2[1]){
                return true;
            }
        }
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>&v) {
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        int n=v.size();
        int mx=v[n-1][1];
        for(int i=n-2;i>=0;i--){
            if(v[i][1]<mx){
                ans++;
            }
            mx=max(mx,v[i][1]);
        }
        return ans;
    }
};