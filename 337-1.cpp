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
        if (root == nullptr) 
            return 0;
        
        // 利用备忘录消除重叠子问题
        if (memo.find(root) != memo.end()) 
            return memo[root];
        
        // 抢，然后去下下家
        int do_it = root->val + (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right)) 
                             + (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));
        // 不抢，然后去下家
        int not_do = rob(root->left) + rob(root->right);

        int ret = max(do_it, not_do);
        memo[root] = ret;
        
        return ret;
    }
private:
    unordered_map<TreeNode *, int > memo;
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
