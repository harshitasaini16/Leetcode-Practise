class Solution {
public:
    int fun(int x){
        int y=0;
        while(x>0){
            y+=(x%10);
            x=x/10;
        }
        return y;
    }
    int countEven(int num) {
        int s=0;
        for(int i=2;i<=num;i++){
            int x=fun(i);
            if(x%2==0){
                s++;
            }
        }
        return s;
    }
};