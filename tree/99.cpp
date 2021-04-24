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
    void recoverTree(TreeNode* root) {
        pPreNode_ = NULL;

        pFirstErrNode_ = NULL;
        pSecondErrNode_ = NULL;

        find_err_node(root);

        int tmp = pFirstErrNode_->val;
        pFirstErrNode_->val = pSecondErrNode_->val;
        pSecondErrNode_->val = tmp;
    }

    void find_err_node(TreeNode *root) {
		if (root == NULL)
			return ;

        find_err_node(root->left);

        if (pPreNode_ != NULL && pPreNode_->val > root->val)
        {
            if (pFirstErrNode_ == NULL)
                pFirstErrNode_ = pPreNode_;

            pSecondErrNode_ = root;
        }   
        else
            pPreNode_ = root;

        find_err_node(root->right);
	}

    TreeNode *pPreNode_;

    TreeNode *pFirstErrNode_;
    TreeNode *pSecondErrNode_;
};

int main()
{
	Solution s;

	return 0;
}
