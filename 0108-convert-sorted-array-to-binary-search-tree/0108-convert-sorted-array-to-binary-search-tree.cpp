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
    /**
     * Converts a sorted array to a height-balanced Binary Search Tree (BST).
     * @param nums - A sorted array in ascending order
     * @return The root node of the constructed BST
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Use helper function to build the tree recursively
        return buildBST(nums, 0, nums.size() - 1);
    }
  
private:
    /**
     * Helper function to recursively build a BST from a sorted array segment.
     * Uses divide-and-conquer approach: middle element becomes root,
     * left half forms left subtree, right half forms right subtree.
     * 
     * @param nums - Reference to the sorted array
     * @param left - Starting index of the current segment (inclusive)
     * @param right - Ending index of the current segment (inclusive)
     * @return Root node of the subtree constructed from nums[left...right]
     */
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
  
        int mid = (left + right) >> 1;

        TreeNode* root = new TreeNode(
            nums[mid],
            buildBST(nums, left, mid - 1),
            buildBST(nums, mid + 1, right)
        );
      
        return root;
    }
};