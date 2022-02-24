class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int fac=1;
        for(int i=1;i<n;i++){
            v.push_back(i);
            fac*=i;
        }
        k--;
        v.push_back(n);
        string s="";
        while(true){
            s=s+to_string(v[k/fac]);
            v.erase(v.begin()+k/fac);
            if(v.size()==0){
                break;
            }
            k=k%fac;
            fac=fac/v.size();
        }
        return s;
    }
};