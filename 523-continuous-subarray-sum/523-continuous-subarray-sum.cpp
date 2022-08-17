class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long long,int>m;
        int n=nums.size();
        if(n<=1){
            return false;
        }
        int c=0;
        long long s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(nums[i]==0){
                c++;
            }
            else{
                c=0;
            }
            if(c>1){
                return true;
            }
            else if(s>0 && s%k==0 && i>0){
                cout<<i<<' ';
                return true;
            }
            int x=s%k;
            if(x!=0 && m.find(x)!=m.end()){
                int y=i-m[x];
                if(y>1){
                    cout<<i<<' ';
                    return true;
                }
            }
            else if(x>0){
                m[x]=i;
            }
        }
        return false;
    }
};