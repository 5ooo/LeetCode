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
    void recoverTree(TreeNode* root) {
        pPrevNode = NULL;
        pFirstNode = NULL;
        pSecondNode = NULL;

        find_err_node(root);

        int tmp = pFirstNode->val;
        pFirstNode->val = pSecondNode->val;
        pSecondNode->val = tmp;
    }   

    void find_err_node(TreeNode *root) {
        if (root == NULL)
            return;

        find_err_node(root->left);

        if (pPrevNode != NULL)
        {   
            if (pPrevNode->val > root->val)
            {   
                if (pFirstNode == NULL)
                    pFirstNode = pPrevNode;
                pSecondNode = root;
            }   
        }   
        pPrevNode = root;

        find_err_node(root->right);
    }   

    TreeNode *pPrevNode;
    TreeNode *pFirstNode;
    TreeNode *pSecondNode;

};
