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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
   
        using NodeDepthPair = pair<TreeNode*, int>;

        auto findDeepestSubtree = [&](this auto&& findDeepestSubtree, TreeNode* node) -> NodeDepthPair {

            if (!node) {
                return {nullptr, 1};
            }
            auto [leftSubtree, leftDepth] = findDeepestSubtree(node->left);
            auto [rightSubtree, rightDepth] = findDeepestSubtree(node->right);
            if (leftDepth > rightDepth) {
                return {leftSubtree, leftDepth + 1};
            }
            if (leftDepth < rightDepth) {
                return {rightSubtree, rightDepth + 1};
            }
            return {node, leftDepth + 1};
        };
        return findDeepestSubtree(root).first;
    }
};
