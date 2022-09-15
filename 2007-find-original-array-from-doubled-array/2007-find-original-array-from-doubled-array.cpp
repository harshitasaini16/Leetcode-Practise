class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        sort(a.begin(),a.end());
        map<int,int>m;
        for(int i=0;i<a.size();i++){
            m[a[i]]++;
        }
        vector<int>v;
        for(int i=0;i<a.size();i++){
            if(a[i]==0){
                continue;
            }
            else if(m[a[i]]>0){
                if(m[a[i]*2]>0){
                    v.push_back(a[i]);
                    m[a[i]]--;
                    m[a[i]*2]--;
                }
                else{
                    return {};
                }
            }
        }
        if(m[0]%2!=0){
            return {};
        }
        for(int i=0;i<m[0]/2;i++){
            v.push_back(0);
        }
        return v;
    }
};