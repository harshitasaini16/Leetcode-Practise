class Solution {
public:
    static bool cmp(int n,int m){
        string s1=to_string(n);
        string s2=to_string(m);
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s1[i]<s2[j]){
                return true;
            }
            else if(s1[i]>s2[j]){
                return false;
            }
            i++;
            j++;
        }
        if(n<m){
            return true;
        }
        return false;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};