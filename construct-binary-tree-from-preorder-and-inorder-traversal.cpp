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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft, int iright) {
        if (pleft > pright || ileft > iright)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pleft]);

        int mid = ileft;
        for (; mid < iright; mid++)
        {
            if (inorder[mid] == preorder[pleft])
                break;
        }

        root->left = buildTree(preorder, inorder, pleft + 1, pleft + mid - ileft, ileft, mid - 1);
        root->right = buildTree(preorder, inorder, pleft + mid - ileft + 1, pright, mid + 1, iright);

        return root;
    }   

};
