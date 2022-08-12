class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int duration) {
        int ans=0;
        int mx=0;
        for(int i=1;i<t.size();i++){
            int x=t[i]-t[i-1];
            ans+=min(duration,x);
        }
        return ans+duration;
    }
};
