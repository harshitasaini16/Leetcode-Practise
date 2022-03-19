class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        if(v1[0]<v2[0]){
            return true;
        }
        if(v1[0]==v2[0]){
            if(v1[1]>v2[1]){
                return true;
            }
        }
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>temp;
        for(int i=0;i<envelopes.size();i++)
        {
            auto it = lower_bound(temp.begin(), temp.end(), envelopes[i][1]);
            if(it == temp.end())
                temp.push_back(envelopes[i][1]);
            else
                *it = envelopes[i][1];
        }
        return temp.size();
    }
};