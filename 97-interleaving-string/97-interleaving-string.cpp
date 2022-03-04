class Solution {
private:
    string p, q, s;
    bool f(int i, int j, vector<vector<int>>& dp) {
        if(i == p.size() and j == q.size())
            return 1;
        bool ans = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
         if(i < p.size() and p[i] == s[i + j])
             ans |= f(i + 1, j, dp);
        
         if(j < q.size() and q[j] == s[i + j])
            ans |= f(i, j + 1, dp);

        
       
        return dp[i][j] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
                p = s1, q = s2, s = s3;
        vector<vector<int>> dp(101, vector<int>(101, -1));
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        int i = 0, j = 0;
        return f(i, j, dp);
    }
};