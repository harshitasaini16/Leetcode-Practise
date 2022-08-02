class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int n=heights.size();
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n ||  heights[s.top()]>=heights[i])){
                int height=heights[s.top()];
                s.pop();
                int weight;
                if(s.empty()){
                    weight=i;
                }
                else{
                    weight=i-s.top()-1;
                }
                ans=max(ans,height*weight);
            }
            s.push(i);
        }
        return ans;
    }
};