class Solution {
public:
    int brokenCalc(int s, int target) {
        int ans=0;
        while(s<target){
            if(target%2==0){
                target/=2;
            }
            else{
                target++;
            }
            ans++;
        }
        cout<<s<<' ';
        return ans+(s-target);
    }
};