
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
    int rob(TreeNode* root) {
        //ret[0]表示不抢root,获取的最大钱数
        //ret[1]表示抢root,获取的最大钱数
        vector<int> ret = dp(root);
        return max(ret[0], ret[1]);
    }
    
    vector<int> dp(TreeNode* root) {
        if (root == nullptr) 
            return {0, 0};
        
        vector<int> left = dp(root->left); 
        vector<int> right = dp(root->right);
        
        //抢当前的，则接下来不能抢
        int rob = root->val + left[0] + right[0];
        
        //不抢当前的，接下来可抢可不抢，取收益大的
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {not_rob, rob};
    }
};

