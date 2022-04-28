class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        int s=boxes[0]-'0';
        int last=0;
        for(int i=1;i<n;i++){
            ans[i]=last+s;
            last=ans[i];
            s+=boxes[i]-'0';
        }
        s=boxes[n-1]-'0';
        last=0;
        for(int i=n-2;i>=0;i--){
            ans[i]+=last+s;
            last=s+last;
            s+=boxes[i]-'0';
        }
        return ans;
    }
};
