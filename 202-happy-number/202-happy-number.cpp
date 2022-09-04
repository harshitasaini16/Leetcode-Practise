class Solution {
public:
    bool isHappy(int n) {
        map<int,int>m;
        m[n]++;
        while(n!=1){
            int num=0;
            while(n>0){
                int x=n%10;
                num+=(x*x);
                n=n/10;
            }
            if(m.find(num)!=m.end()){
                return false;
            }
            m[num]++;
            n=num;
        }
        return true;
    }
};