class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto i:m){
            int x=i.first+k;
            if(k==0){
                if(m[i.first]>1){
                    ans++;
                }
            }
            else if(m.find(x)!=m.end()){
                ans++;
            }
        }
        return ans;
    }
};