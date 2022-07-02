class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int p) {
        map<int,int>f;
        for(int i=0;i<forbidden.size();i++){
            f[forbidden[i]]++;
        }
        map<pair<int,int>,int>m;
        queue<pair<int,int>>q;
        int ans=0;
        q.push({0,0});
        m[{0,0}]++;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int z=q.front().second;
                q.pop();
                if(x==p){
                    return ans;
                }
                if(x>10000){
                    return -1;
                }
                int d1=x+a;
                int d2=x-b;
                if(z==1){
                    if(f[d1]==0 && m[{d1,1}]==0 && d1>0 && d1<10000){
                        q.push({d1,1}); 
                        m[{d1,1}]++;
                    }
                    if(f[d2]==0 && m[{d2,0}]==0 && d2>0){
                        q.push({d2,0}); 
                        m[{d2,0}]++;
                    }
                }
                else if(z==0){
                    if(f[d1]==0 && m[{d1,1}]==0 && d1>=0 && d1<10000){
                        q.push({d1,1}); 
                        m[{d1,1}]++;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};