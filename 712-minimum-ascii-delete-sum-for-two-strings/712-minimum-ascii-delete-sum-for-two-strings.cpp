class Solution {
public:
    int mat[1001][1001];
    int fun(string &s1,string &s2,int n,int m){
        if(n==0 && m==0){
            return 0;
        }
        if(n==0){
            return int(s2[m-1])+fun(s1,s2,n,m-1);
        }
        else if(m==0){
            return int(s1[n-1])+fun(s1,s2,n-1,m);
        }
        if(mat[n][m]!=-1){
            return mat[n][m];
        }
        if(s1[n-1]==s2[m-1]){
            return mat[n][m]=fun(s1,s2,n-1,m-1);
        }
        return mat[n][m]=min({int(s1[n-1])+fun(s1,s2,n-1,m),int(s2[m-1])+fun(s1,s2,n,m-1),int(s1[n-1])+int(s2[m-1])+fun(s1,s2,n-1,m-1)});
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(mat,-1,sizeof(mat));
        return fun(s1,s2,s1.length(),s2.length());
    }
};