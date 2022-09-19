class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>s;
        int n=h.size();
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || h[s.top()]>h[i])){
                int x=h[s.top()];
                s.pop();
                int y;
                if(s.empty()){
                    y=i;
                }
                else{
                    y=i-s.top()-1;
                }
                ans=max(ans,x*y);
            }
            s.push(i);
        }
        return ans;
    }
};