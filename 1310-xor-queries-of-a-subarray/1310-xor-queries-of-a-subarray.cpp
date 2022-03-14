class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>v;
        int x=arr[0];
        v.push_back(x);
        for(int i=1;i<arr.size();i++){
            x=x^arr[i];
            v.push_back(x);
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            if(x==0){
                ans.push_back(v[y]);
            }
            else{
                ans.push_back(v[y]^v[x-1]);
            }
        }
        return ans;
    }
};