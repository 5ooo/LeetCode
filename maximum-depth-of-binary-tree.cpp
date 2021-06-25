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
    int maxDepth(TreeNode* root) {
        return max_depth(root, 0); 
    }   

    int max_depth(TreeNode* root, int level)
    {   
        if (root == NULL)
            return level;

        return max(max_depth(root->left, level + 1), max_depth(root->right, level + 1));
    }
};
