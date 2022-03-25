class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>&v) {
        priority_queue<pair<int,int>>q;
        map<int,int>m;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        for(auto i:m){
            q.push({i.second,i.first});
        }
        v.clear();
        while(!q.empty()){
            if(q.size()==1){
                v.push_back(q.top().second);
                q.pop();
            }
            else{
                int x1=q.top().first,y1=q.top().second;
                q.pop();
                int x2=q.top().first,y2=q.top().second;
                q.pop();
                v.push_back(y1);
                v.push_back(y2);
                x1--;
                x2--;
                if(x1!=0){
                    q.push({x1,y1});
                }
                if(x2!=0){
                    q.push({x2,y2});
                }
            }
        }
        return v;
    }
};