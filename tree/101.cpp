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
    bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return false;

        return is_symmetric(root->left, root->right);
    }

	bool is_symmetric(TreeNode *left, TreeNode *right)
	{
		if (left == NULL && right == NULL)
			return true;
		else if (left == NULL && right != NULL)
			return false;
		else if (left != NULL && right == NULL)
			return false;

		if (left->val != right->val)
			return false;

		return is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left);
	}
};

int main()
{
	Solution s;

	return 0;
}
