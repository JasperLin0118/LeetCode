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
    int averageOfSubtree(TreeNode* root) 
    {
        int curr_sum = 0, curr_nodes = 0, ans = 0;
        dfs(root, curr_sum, curr_nodes, ans);
        return ans;
    }
    pair<int, int> dfs(TreeNode* curr, int curr_sum, int curr_nodes, int &ans)
    {
        pair<int, int> left;
        pair<int, int> right;
        if(curr->left)
            left = dfs(curr->left, curr_sum, curr_nodes, ans);
        if(curr->right)
            right = dfs(curr->right, curr_sum, curr_nodes, ans);
        curr_sum += left.first + right.first + curr->val;
        curr_nodes += 1 + left.second + right.second;
        if(curr_sum / curr_nodes == curr->val)
            ans++;
        return make_pair(curr_sum, curr_nodes);
    }
};