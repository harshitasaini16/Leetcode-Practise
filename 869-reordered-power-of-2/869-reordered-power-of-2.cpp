class Solution {
public:
    bool fun(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    bool reorderedPowerOf2(int n) {
        int x=1;
        vector<int>v;
        while(x<1e9){
            v.push_back(x);
            x*=2;
        }
        for(int i=0;i<v.size();i++){
            string a=to_string(v[i]);
            string b=to_string(n);
            if(fun(a,b)){
                return true;
            }
        }
        return false;
    }
};