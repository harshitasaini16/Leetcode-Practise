class Solution {
public:
    int find(int x,vector<int>&root){
        if(root[x]==-1){
            return x;
        }
        return root[x]=find(root[x],root);
    }
    void merge(int x,int y,vector<int>&rank,vector<int>&root){
        int rx=find(x,root);
        int ry=find(y,root);
        if(rx==ry){
            return;
        }
        if(rank[rx]>=rank[ry]){
            root[ry]=rx;
            rank[rx]+=rank[ry];
        }
        else{
            root[rx]=ry;
            rank[ry]+=rank[rx];
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<int>rank(n,1);
        vector<int>root(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    merge(i,j,rank,root);
                }
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            if(root[i]==-1){
                s++;
            }
        }
        return s;
    }
};