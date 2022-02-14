class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        vector<pair<int,int>>v;
        for(int i=0;i<plant.size();i++){
            v.push_back({grow[i],plant[i]});
        }
        sort(v.rbegin(),v.rend());
        int mx=0;
        int s=0;
        for(int i=0;i<v.size();i++){
            int day=s+(v[i].first+v[i].second);
            mx=max(mx,day);
            s=s+v[i].second;
        }
        return mx;
    }
};