class Solution {
public:
    bool cmp(vector<int>v1,vector<int>v2){
        if(v1[0]==v2[0]){
            return true;
        }
        if(v1[0]==v2[0]){
            if(v1[1]<v2[1]){
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<pair<int,int>>v;
        for(int i=0;i<b.size();i++){
            v.push_back({b[i][0],-b[i][2]});
            v.push_back({b[i][1],b[i][2]});
        }
        sort(v.begin(),v.end());
        multiset<int>s;
        s.insert(0);
        vector<vector<int>>ans;
        int mx=0;
        for(int i=0;i<v.size();i++){
            if(v[i].second<0){
                s.insert(abs(v[i].second));
            }
            else{
                s.erase(s.find(v[i].second));
            }
            if(mx!=*s.rbegin()){
                mx=*s.rbegin();
                ans.push_back({v[i].first,mx});
            }
        }
        return ans;
    }
};