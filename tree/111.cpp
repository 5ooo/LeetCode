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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

		int l_level = minDepth(root->left);
		int r_level = minDepth(root->right);

		if (l_level == 0 && r_level == 0)
			return 1;
		else if (l_level == 0 && r_level != 0)
			return r_level + 1;
		else if (l_level != 0 && r_level == 0)
			return l_level + 1;
		else
			return min(l_level, r_level) + 1;
    }
    
};


int main()
{
	Solution s;

	return 0;
}
