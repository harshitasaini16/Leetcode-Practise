class Solution {
public:
	int mod = 1e9 + 7;
    int dp[100005][3];
    
    int solve(string& s, int cnt, int idx, int n) {
        if(idx == n) {
            return (cnt == 2);
        }
        
        if(dp[idx][cnt]  != -1) return dp[idx][cnt];
        
        int res = 0;
        
        if(cnt == 2) {
            if(s[idx] == 'S') {
                res += solve(s, 1, idx+1, n);
            }
            else {
                res += solve(s, 0, idx+1, n) + solve(s, cnt, idx+1, n);
            }
        }
        else {
            res += solve(s, cnt + (s[idx] == 'S') , idx+1, n);
        }
        
        return dp[idx][cnt] = res % mod;
    }
    
    int numberOfWays(string corridor) {
        
        int n = corridor.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(corridor, 0, 0, n);
    }
};