class Solution {
public:
    double fun(double x,int n){
        if(n==0){
            return 1;
        }
        double s=fun(x,n/2);
        if(n%2==0){
            return (double)s*s;
        }
        else{
            return (double)s*s*x;
        }
    }
    double myPow(double x, int n) {
        bool f=true;
        if(n<0){
            f=false;
        }
        double s=fun(x,abs(n));
        if(f==false){
            double ans=(double)1/(double)s;
            return ans;
        }
        return s;
    }
};