class Solution {
public:
    bool static cmp(vector<int>&v1,vector<int>&v2){
        if(v1[0]<v2[0]){
            return true;
        }
        else if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return false;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
        vector<vector<int>>v;
        for(auto x:arr){
            v.push_back({x[0],-x[2]});
            v.push_back({x[1],x[2]});
        }
        sort(v.begin(),v.end(),cmp);
        multiset<int>s{0};
        vector<vector<int>>ans;
        int top=0;
        for(auto x:v){
            if(x[1]<0){
                s.insert(-x[1]);
            }else{
                s.erase(s.find(x[1]));
            }
            if(*s.rbegin()!=top){
                top=*s.rbegin();
                ans.push_back({x[0],*s.rbegin()});
            }
        }
        return ans;
    }
    
};