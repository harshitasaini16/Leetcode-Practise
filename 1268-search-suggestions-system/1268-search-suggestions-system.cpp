class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string w) {
        map<string,vector<string>>m;
        for(int i=0;i<products.size();i++){
            string s=products[i];
            for(int j=1;j<=s.length();j++){
                string h=s.substr(0,j);
                m[h].push_back(s);
            }
        }
        // for(auto i:m){
        //     sort(i.second.begin(),i.second.end());
        // }
        vector<vector<string>>ans;
        for(int i=1;i<=w.length();i++){
            string g=w.substr(0,i);
            vector<string>v=m[g];
            sort(v.begin(),v.end());
            if(v.size()<=3){
                ans.push_back(v);
            }
            else
            ans.push_back({v[0],v[1],v[2]});
        }
        return ans;
    }
};