class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0)
            return 0;

        vector<vector<int> > path(m, vector<int>(n, 0));
        for(int j = 0; j < n; j++) //row
            path[0][j] = 1;
        for(int i = 0; i < m; i++) //col
            path[i][0] = 1;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                path[i][j] = path[i-1][j] + path[i][j-1];

        return path[m -1][n -1]; 
    }
};
