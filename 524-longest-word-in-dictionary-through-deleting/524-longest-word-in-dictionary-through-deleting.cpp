class Solution {
public: 
    string findLongestWord(string s, vector<string>& d) {
        int ans2=0;
        string ans1="";
        sort(d.begin(),d.end());
        for(int i=0;i<d.size();i++){
            string s1=s;
            string s2=d[i];
            int x=0;
            int y=0;
            int n=s.length();
            int m=s2.length();
            while(x<n && y<m){
                if(s1[x]==s2[y]){
                    x++;
                    y++;
                }
                else{
                    x++;
                }
            }
            if(y==m && m>ans2){
                ans2=m;
                ans1=s2;
            }
        }
        return ans1;
    }
};