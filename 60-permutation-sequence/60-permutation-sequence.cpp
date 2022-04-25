class Solution {
public:
    string getPermutation(int n, int k) {
        int s=1;
        vector<int>v;
        for(int i=1;i<n;i++){
            s*=i;
            v.push_back(i);
        }
        string ans="";
        k--;
        v.push_back(n);
        while(true){
            int y=k/s;
            ans+=to_string(v[y]);
            v.erase(v.begin()+y);
            if(v.size()==0){
                break;
            }
            k=k%s;
            s=s/v.size();
        }
        return ans;
    }
};