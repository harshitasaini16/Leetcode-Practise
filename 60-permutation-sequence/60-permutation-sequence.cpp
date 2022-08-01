class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int s=1;
        for(int i=1;i<=n-1;i++){
            v.push_back(i);
            s*=i;
        }
        string ans="";
        v.push_back(n);
        k--;
        while(true){
            int x=k/s;
            ans=ans+to_string(v[x]);
            v.erase(v.begin()+x);
            if(v.size()==0){
                break;
            }
            k=k%s;
            s=s/v.size();
        }
        return ans;
    }
};