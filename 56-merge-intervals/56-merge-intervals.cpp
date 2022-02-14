class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        vector<int>v;
        int x;
        for(int i=0;i<n;i++){
            if(v.size()==0){
                v.push_back(intervals[i][0]);
                x=intervals[i][1];
            }
            else{
                if(intervals[i][0]<=x){
                    x=max(x,intervals[i][1]);
                }
                else{
                    v.push_back(x);
                    ans.push_back(v);
                    v.clear();
                    v.push_back(intervals[i][0]);
                    x=intervals[i][1];
                }
            }
        }
        v.push_back(x);
        ans.push_back(v);
        return ans;
    }
};