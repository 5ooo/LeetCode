#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

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
        vector<int> ret = dp(root);
        return max(ret[0], ret[1]);
    }

    vector<int> dp(TreeNode* root) {
        if (root == nullptr) 
            return vector<int> ret(2, 0);
       
        vector<int> left = dp(root->left); 
        vector<int> right = dp(root->right); 
        
        int rob = root->val + left[0] + right[0];
 
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        
        vector<int> ret = {rob, not_rob};

        return ret;
    }
};
int main()
{
        vector<i
	test.push_back(2);
	test.push_back(3);
	test.push_back(2);

	Solution s;

	printf("%d\n", s.rob(test));

	return 0;
}
