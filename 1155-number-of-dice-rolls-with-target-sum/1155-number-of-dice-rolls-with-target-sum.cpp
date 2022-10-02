class Solution {
public:
    const int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        // dp[i][s] = sum (dp[i - 1][s - x]) where: 1 <= x <= k, 1 <= i <= n, 1 <= s <= target
        
        int dp[n + 1][target + 1];
        
        for(int i = 1; i <= n; i++) {
            dp[i][0] = 0; // using any number of dices sum = 0 cannot be obtained
        }
        dp[0][0] = 1; // one way to get 0 sum using 0 dice
        for(int i = 1; i <= target; i++) {
            dp[0][i] = 0; // using zero dice we cannot obtain any non-zero sum
        }
        
        for(int i = 1; i <= n; i++) {
            for(int s = 1; s <= target; s++) {
                int sum = 0;
                for(int x = 1; x <= min(s, k); x++) {
                    sum += dp[i - 1][s - x];
                    sum %= mod;
                }
                dp[i][s] = sum;
            }
        }
        return dp[n][target];
    }
};
