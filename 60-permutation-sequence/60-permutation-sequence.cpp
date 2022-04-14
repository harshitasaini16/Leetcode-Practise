class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        int x=1;
        vector<int>v;
        for(int i=1;i<n;i++){
            v.push_back(i);
            x=x*i;
        }
        k--;
        v.push_back(n);
        while(true){
            int y=k/x;
            ans+=to_string(v[y]);
            v.erase(v.begin()+y);
            if(v.size()==0){
                break;
            }
            k=k%x;
            x=x/v.size();
        }
        return ans;
    }
};