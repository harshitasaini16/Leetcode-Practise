class Solution {
public:
    map<int,int>m;
    int f(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(m.find(n)!=m.end()){
            return m[n];
        }
        return m[n]=f(n-1)+f(n-2);
    }
    int climbStairs(int n) {
        m.clear();
        return f(n);
    }
};