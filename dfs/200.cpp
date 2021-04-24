#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != '0')
                {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        
        return cnt;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if ((i >= 0 && i < grid.size())     &&
            (j >= 0 && j < grid[0].size())  &&
            (grid[i][j] != '0')             )
        {
            grid[i][j] = '0';
            
            dfs(grid, i + 1, j);
            dfs(grid, i - 1, j);
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
        }
    }
};


int main()
{
	Solution s;

	return 0;
}
