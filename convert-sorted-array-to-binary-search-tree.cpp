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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *ret;

        sorted_array_to_bst(nums, 0, nums.size() - 1, &ret);

        return ret;
    }

    void sorted_array_to_bst(vector<int>& nums, int l_bound, int r_bound, TreeNode **root) 
    {
        if (l_bound > r_bound)
        {
            *root = nullptr;
            return ;
        }

        int middle = (l_bound + r_bound) / 2;
        *root = new TreeNode(nums[middle]);

        sorted_array_to_bst(nums, l_bound, middle - 1, &((*root)->left));

        sorted_array_to_bst(nums, middle + 1, r_bound, &((*root)->right));
    }
};
