class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2){
        if(p1.first==p2.first){
            if(p1.second>p2.second){
                return true;
            }
        }
        return p1.first<p2.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        int n=v.size();
        sort(v.begin(),v.end(),cmp);
        int i=0;
        priority_queue<int>q;
        while(k--){
            for(;i<n;i++){
                if(v[i].first<=w){
                    q.push(v[i].second);
                }
                else{
                    break;
                }
            }
            if(q.empty()){
                break;
            }
            else{
                w+=q.top();
                q.pop();
            }
        }
        return w;
    }
};