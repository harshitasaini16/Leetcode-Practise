class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        if(k<2) return mat[0][0];
        int l=mat[0][0];
        int r=mat[n-1][n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            int pos=0;
            for(int i=0;i<n;i++){
                int x=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
                pos+=x;
            }
            if(pos<k){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
};