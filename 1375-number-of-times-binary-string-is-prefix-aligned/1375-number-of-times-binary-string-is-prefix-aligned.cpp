class Solution {
public:
    int numTimesAllBlue(vector<int>& flip) {
        int n=flip.size();
        string s="";
        for(int i=0;i<n;i++){
            s.push_back('0');
        }
        int ans=0;
        for(int i=0;i<n;i++){
            s[flip[i]-1]='1';
            int x=0;
            if(s.find('0')>i){
                ans++;
            }
        }
        return ans;
    }
};