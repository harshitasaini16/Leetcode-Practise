class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int x=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<x){
                x=prices[i];
            }
            else{
                ans=max(ans,prices[i]-x);
            }
        }
        return ans;
    }
};