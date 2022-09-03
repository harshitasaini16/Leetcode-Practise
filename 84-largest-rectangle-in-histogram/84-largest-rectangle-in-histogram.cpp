class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || heights[s.top()]>heights[i])){
                int x=heights[s.top()];
                s.pop();
                int y;
                if(s.empty()){
                    y=i;
                }
                else{
                    y=i-s.top()-1;
                }
                ans=max(ans,(x*y));
            }
            s.push(i);
        }
        return ans;
    }
};