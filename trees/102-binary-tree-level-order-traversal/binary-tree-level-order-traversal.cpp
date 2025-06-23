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
     * Function: levelOrder
     *
     * Description:
     * Performs a level-order traversal (breadth-first search) on a binary tree
     * and returns a list of node values grouped by depth level.
     *
     * Time Complexity: O(n)
     *   - Each node is visited once.
     *
     * Space Complexity: O(n)
     *   - Queue stores up to one full level of nodes.
     *
     * Strategy:
     *   - Use a queue to track nodes at each level.
     *   - For each level, process all nodes and collect their values.
     *   - Push their children into the queue for the next level.
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();     // Number of nodes in current level
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);   // Add node value to current level

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);  // Save completed level
        }

        return result;
    }
};
