class Solution {
public:
    int findMinMoves(vector<int>& a) {
        int sum=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum%n!=0){
            return -1;
        }
        int ans=0;
        int want=sum/n;
        int left=0;
        int right=sum;
        for(int i=0;i<n;i++){
            left+=a[i];
            int l=want*(i+1);
            int c=0;
            if(left>l){
                c+=(left-l);
            }
            int r=(n-i)*want;
            if(right>r){
                c+=(right-r);
            }
            ans=max(ans,c);
            right-=a[i];
        }
        return ans;
    }
};