class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& a) {
        map<int,int>m;
        for(int i=0;i<target.size();i++){
            m[target[i]]=i;
        }
        vector<int>arr;
        for(int i=0;i<a.size();i++){
            if(m.find(a[i])!=m.end()){
                arr.push_back(m[a[i]]);
            }
        }
        int ans=0;
        vector<int>dp;
        if(arr.size()==0){
            return target.size();
        }
        dp.push_back(arr[0]);
        int len=1;
        for(int i=1;i<arr.size();i++){
            if(dp.back()<arr[i]){
                dp.push_back(arr[i]);
                len++;
            }
            else{
                int x=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
                dp[x]=arr[i];
            }
        }
        return target.size()-len;
    }
};
