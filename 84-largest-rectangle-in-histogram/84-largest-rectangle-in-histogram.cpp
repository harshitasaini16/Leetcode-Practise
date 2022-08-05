class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>l(n),r(n);
        stack<int>s;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                l[i]=-1;
            }
            else{
                l[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                r[i]=n;
            }
            else{
                r[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int left=(l[i]+1);
            int right=(r[i]-1);
            int x=right-left+1;
            ans=max(ans,heights[i]*x);
        }
        return ans;
    }
};