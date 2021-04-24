#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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


int main()
{
	Solution s;

	printf("%d\n", s.numTrees(3));

	return 0;
}
