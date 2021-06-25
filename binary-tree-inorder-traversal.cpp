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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;

        if(root == NULL)
            return ret;

        traversal(root, ret);

        return ret;
    }   

    void traversal(TreeNode *node, vector<int> &v) 
    {   
        if (node == NULL)
            return ;

        traversal(node->left, v); 

        v.push_back(node->val);    

        traversal(node->right, v); 
    } 
};
