class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int s=-1,e;
        for(int i=0;i<intervals.size();i++){
            if(s==-1){
                s=intervals[i][0];
                e=intervals[i][1];
            }
            else{
                if(intervals[i][0]<=e){
                    e=max(e,intervals[i][1]);
                }
                else{
                    ans.push_back({s,e});
                    s=intervals[i][0];
                    e=intervals[i][1];
                }
            }
        }
        ans.push_back({s,e});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>&ni) {
        intervals.push_back(ni);
        return merge(intervals);
    }
};