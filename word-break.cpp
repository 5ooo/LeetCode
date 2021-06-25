class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us; 
        for (int i = 0; i < wordDict.size(); i++)
            us.insert(wordDict[i]);

        vector<int> dp(s.length() + 1, 0); 

        dp[0] = 1;

        for (int i = 1; i <= s.length(); i++)
        {   
            for (int j = 0; j < i; j++)
            {   
                if (dp[j] && us.find(s.substr(j, i - j)) != us.end())
                    dp[i] = 1;
            }   
        }   

        return dp[s.length()];
    } 
};
