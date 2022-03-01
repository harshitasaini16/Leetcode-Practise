class Solution {
public:
    int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;
    else
        return 1 + countSetBits(n & (n - 1));
}
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i=0;i<=n;i++){
            int x=countSetBits(i);
            v.push_back(x);
        }
        return v;
    }
};