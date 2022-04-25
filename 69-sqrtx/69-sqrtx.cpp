class Solution {
public:
    int mySqrt(int x) {
        long long y=0;
        for(long long i=1;i*i<=x;i++){
            if(i*i<=x){
                y=max(y,i);
            }
        }
        return y;
    }
};