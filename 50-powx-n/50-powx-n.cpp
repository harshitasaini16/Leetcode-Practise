class Solution {
public:
    double fun(double x,int y){
        if(y==0){
            return 1;
        }
        double z=fun(x,y/2);
        if(y%2==0){
            return z*z;
        }
        else{
            return z*z*x;
        }
    }
    double myPow(double x, int n) {
        if(n<0){
            return 1/fun(x,abs(n));
        }
        return fun(x,n);
    }
};