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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;

        vector<int> tmp;

        pathSum(root, sum, tmp, ret);

        return ret;
    }

    void pathSum(TreeNode* root, int sum, vector<int> &tmp, vector<vector<int>> &ret)
    {   
        if (root == NULL)
            return ;
        
        if (root->val == sum && root->left == NULL && root->right == NULL)
        {
            tmp.push_back(root->val);
            ret.push_back(tmp);
            tmp.pop_back();
            return ;
        }

        tmp.push_back(root->val);

        pathSum(root->left, sum - root->val, tmp, ret);

        pathSum(root->right, sum - root->val, tmp, ret);
        
        tmp.pop_back();
    }
};
