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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int ileft, int iright, int pleft, int pright) {
        if (ileft > iright || pleft > pright)
            return NULL;

        TreeNode *root = new TreeNode(postorder[pright]);

        int mid = ileft;
        for (; mid <= iright; mid++)
        {
            if (inorder[mid] == postorder[pright])
                break;
        }

        root->left = buildTree(inorder, postorder, ileft, mid - 1, pleft, pleft + (mid - ileft - 1));
        root->right = buildTree(inorder, postorder, mid + 1, iright, pleft + (mid - ileft), pright - 1);

        return root;
    }   
};
