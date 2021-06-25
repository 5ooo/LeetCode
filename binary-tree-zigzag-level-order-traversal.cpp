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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
                
        level_order(root, ret, 0);    

        return ret;
    }   

    void level_order(TreeNode *root, vector<vector<int>> &ret, int level)
    {   
        if (root == NULL)
            return ;

        while (ret.size() <= level)
            ret.push_back(vector<int>());
        
        if (level % 2)
            ret[level].insert(ret[level].begin(), root->val);
        else
            ret[level].push_back(root->val);

        level_order(root->left, ret, level + 1); 

        level_order(root->right, ret, level + 1); 

        
    }
};
