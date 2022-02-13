class Solution {
public:
    int fun1(vector<int>nums){
        map<int,int>m;
        int n1=0,n2=0;
        for(int i=0;i<nums.size();i+=2){
            m[nums[i]]++;
            n1++;
        }
        n2=nums.size()-n1;
        int count=0,dig=0;
        for(auto i:m){
            if(i.second>count){
                count=i.second;
                dig=i.first;
            }
        }
        int ans=n1-count;
        map<int,int>m2;
        for(int i=1;i<nums.size();i+=2){
            m2[nums[i]]++;
        }
        int s=n2;
        for(int i=1;i<nums.size();i+=2){
            if(nums[i]!=dig){
                s=min(s,n2-m2[nums[i]]);
            }
        }
        ans+=s;
        return ans;
    }
    int fun2(vector<int>nums){
        map<int,int>m;
        int n1=0,n2=0;
        for(int i=1;i<nums.size();i+=2){
            m[nums[i]]++;
            n1++;
        }
        n2=nums.size()-n1;
        int count=0,dig=0;
        for(auto i:m){
            if(i.second>count){
                count=i.second;
                dig=i.first;
            }
        }
        int ans=n1-count;
        map<int,int>m2;
        for(int i=0;i<nums.size();i+=2){
            m2[nums[i]]++;
        }
        int s=n2;
        for(int i=0;i<nums.size();i+=2){
            if(nums[i]!=dig){
                s=min(s,n2-m2[nums[i]]);
            }
        }
        ans+=s;
        return ans;
    }
    int minimumOperations(vector<int>& nums) {
        int x=fun1(nums);
        int y=fun2(nums);
        cout<<x<<' '<<y;
        return min(x,y);
    }
};