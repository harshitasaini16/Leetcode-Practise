class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int mn=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]>mn){
                ans=max(ans,prices[i]-mn);
            }
            else{
                mn=prices[i];
            }
        }
        return ans;
    }
};