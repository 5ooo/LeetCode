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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if ((i >= 0 && i < grid.size())     && 
            (j >= 0 && j < grid[0].size())  && 
            (grid[i][j] == 1)               )
        {
            grid[i][j] = 0;
            
            int num =   dfs(grid, i-1, j) + 
                        dfs(grid, i, j-1) + 
                        dfs(grid, i+1, j) + 
                        dfs(grid, i, j+1) + 1;
            
            return num;
        }
        
        return 0;
    }
};


int main()
{
	Solution s;

	return 0;
}
