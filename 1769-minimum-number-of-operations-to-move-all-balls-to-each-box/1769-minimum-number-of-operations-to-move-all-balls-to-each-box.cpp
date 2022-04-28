class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i]+=(abs(i-j)*(boxes[j]-'0'));
            }
        }
        return ans;
    }
};