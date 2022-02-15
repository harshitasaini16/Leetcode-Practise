class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n=h.size();
        stack<int>s;
        vector<int>ans(n,0);
        s.push(h[n-1]);
        for(int i=n-2;i>=0;i--){
            int c=0;
            while(!s.empty() && s.top()<h[i]){
                s.pop();
                c++;
            }
            if(s.empty()){
                ans[i]=c;
            }
            else{
                ans[i]=c+1;
            }
            s.push(h[i]);
        }
        return ans;
    }
};