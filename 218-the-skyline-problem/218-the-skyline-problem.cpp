class Solution {
public:
    bool static cmp(vector<int>&v1,vector<int>&v2){
        if(v1[0]<v2[0]){
            return true;
        }
        if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return false;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>&arr) {
        vector<vector<int>>v;
        for(auto x:arr){
            v.push_back({x[0],-x[2]});
            v.push_back({x[1],x[2]});
        }
        vector<vector<int>>ans;
        sort(v.begin(),v.end(),cmp);
         multiset<int> ss = {0};                
        int top = 0;                                        
        for (auto w : v) {
            if (w[1] < 0) {                             
               ss.insert(-w[1]);
            } else {                                        
                ss.erase(ss.find(w[1]));
            }
            if (*ss.rbegin() != top) {      
                top = *ss.rbegin();
                ans.push_back({w[0],*ss.rbegin()});
                
            }
        }
        return ans;
    }
};