class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int mn=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>mn){
                mx=max(mx,prices[i]-mn);
            }
            else{
                mn=prices[i];
            }
        }
        return mx;
    }
};