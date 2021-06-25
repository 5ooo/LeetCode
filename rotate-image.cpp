class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j < n - i - 1; j++)
            {
                //A[i][j] -> A[j][n-1-i] -> A[n-1-i][n-1-j] -> A[n-1-j][i] -> A[i][j]
                int temp = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = temp;
            }
        }
    }

};
