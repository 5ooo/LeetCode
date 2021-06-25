class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1)
            return 1;

        vector<int> dp(n + 1); 

        dp[0] = 1;    
        dp[1] = 1;    

        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                dp[i] += dp[i - j - 1] * dp[j];

        return dp[n];
    }
};