class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int s=0;
        int n=cost.size();
        int i=n-1;
        while(i>=0){
            s+=cost[i];
            i--;
            if(i>=0){
                s+=cost[i];
            }
            i-=2;
        }
        return s;
    }
};