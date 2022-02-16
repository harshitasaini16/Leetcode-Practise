class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>m;
        for(int i=1;i<=n;i++){
            int s=0;
            int x=i;
            while(x>0){
                s+=x%10;
                x=x/10;
            }
            m[s]++;
        }
        int mx=0;
        for(auto i:m){
            cout<<i.first<<' ';
            mx=max(mx,i.second);
        }
        int d=0;
        for(auto i:m){
            if(i.second==mx){
                d++;
            }
        }
        return d;
    }
};