class Solution {
public:
    void add(int l,int m,int r,vector<pair<int,int>>&v,vector<int>&count){
        vector<pair<int,int>>tmp(r-l+1);
        int i=l;
        int j=m+1;
        int k=0;
        while(i<=m && j<=r){
            if(v[i].first<=v[j].first){
                tmp[k]=v[j];
                j++;
                k++;
            }
            else{
                count[v[i].second]+=(r-j+1);
                tmp[k]=v[i];
                i++;
                k++;
            }
        }
        while(i<=m){
            tmp[k]=v[i];
            i++;
            k++;
        }
        while(j<=r){
            tmp[k]=v[j];
            j++;
            k++;
        }
        for(int i=l;i<=r;i++){
            v[i]=tmp[i-l];
        }
    }
    void merge(int l,int r, vector<pair<int,int>>&v,vector<int>& count){
        if(l<r){
            int mid=l+(r-l)/2;
            merge(l,mid,v,count);
            merge(mid+1,r,v,count);
            add(l,mid,r,v,count);
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>count(nums.size(),0);
        int n = nums.size();

        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; i++)   
            v[i] = make_pair(nums[i], i);

        merge(0,n-1,v,count);
        return count;
    }
};