class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string x="";
        int n=s.length();
        int d=0;
        for(int i=0;i<n;i++){
            x+=s[i];
            d++;
            if(d==k){
                ans.push_back(x);
                x="";
                d=0;
            }
            else if(i==n-1 && d<k){
                while(d<k){
                    x+=fill;
                    d++;
                }
                ans.push_back(x);
            }
        }
        return ans;
    }
};