class Solution {
public:
    vector<int>ans;
    void fun(int x,int n,int k,int dig){
        if(dig==n){
            ans.push_back(x);
            return;
        }
        int x1=(x%10)+k;
        int x2=(x%10)-k;
        if(x1<=9){
            fun((x*10)+x1,n,k,dig+1);
        }
        if(x2>=0 && x1!=x2){
            fun((x*10)+x2,n,k,dig+1);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        ans.clear();
        for(int i=1;i<=9;i++){
            fun(i,n,k,1);
        }
        return ans;
    }
};