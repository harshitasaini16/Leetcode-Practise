class Solution {
public:
    int reverse(int x) {
        if(x>INT_MAX || x<INT_MIN){
            return 0;
        }
        if(x==0){
            return 0;
        }
        int f=x/abs(x);
        long long ans=0;
        x=abs(x);
        while(x>0 && x%10==0){
            x/=10;
        }
        if(x==0){
            return 0;
        }
        while(x>0){
            ans=(ans*10)+(x%10);
            x/=10;
        }
        if(ans>INT_MAX || ans<INT_MIN){
            return 0;
        }
        return f*ans;
    }
};