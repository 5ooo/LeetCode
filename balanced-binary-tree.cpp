/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int l_level = get_level(root->left, 1);
        int r_level = get_level(root->right, 1);

        if (abs(l_level - r_level) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;
    }
    
    int get_level(TreeNode *root, int level)
    {
        if (root == NULL)
            return level;

        return max(get_level(root->left, level + 1), get_level(root->right, level + 1));
    }
};
