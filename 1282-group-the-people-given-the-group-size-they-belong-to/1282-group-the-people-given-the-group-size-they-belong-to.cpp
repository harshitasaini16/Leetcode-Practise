class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        vector<vector<int>>ans;
        int n=a.size();
        vector<pair<int,int>>v;
        for(int i=0;i<a.size();i++){
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        int i=0;
        while(i<n){
            int j=v[i].first;
            vector<int>b;
            while(j--){
                b.push_back(v[i].second);
                i++;
            }
            ans.push_back(b);
        }
        return ans;
    }
};