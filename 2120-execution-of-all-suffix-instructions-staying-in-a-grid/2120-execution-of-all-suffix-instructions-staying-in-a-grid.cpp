class Solution {
public:
    void valid(int x,int y,string &s,int i,int n,int &z){
        if(s[i]=='R'){
            if(y+1<n){
                z++;
                valid(x,y+1,s,i+1,n,z);
            }
            
        }
        else if(s[i]=='L'){
            if(y-1>=0){
                z++;
                valid(x,y-1,s,i+1,n,z);
            }
  
        }
        else if(s[i]=='U'){
            if(x-1>=0){
                z++;
                valid(x-1,y,s,i+1,n,z);
            }

        }
        else if(s[i]=='D'){
            if(x+1<n){
                z++;
                valid(x+1,y,s,i+1,n,z);
            }

        }
    }
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            int z=0;
            valid(st[0],st[1],s,i,n,z);
            ans.push_back(z);
        }
        return ans;
    }
};