class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        vector<int>v;
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.rbegin(),v.rend());
        int s=arr.size();
        for(int i=0;i<v.size();i++){
            s-=v[i];
            if(s<=arr.size()/2){
                return i+1;
            }
        }
        return v.size();
    }
};