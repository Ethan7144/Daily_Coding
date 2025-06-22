
## What Are Trees?

A **tree** is a hierarchical data structure with nodes connected by edges. A **binary tree** has at most two children per node. **BSTs** follow left < root < right order.

---

## When to Use Trees

* Traverse hierarchical data
* Structure recursion problems
* Store sorted data (BST)
* Evaluate relationships between nodes (e.g., LCA)

---

## Key Tree Patterns (C++)

### Preorder / Inorder / Postorder DFS

```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    // Preorder: process before recursion
    dfs(node->left);
    // Inorder: process in-between
    dfs(node->right);
    // Postorder: process after recursion
}
```

### BFS / Level Order

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}
```

---

## Tips to Remember

* Use recursion for DFS traversals
* BFS for level-by-level logic or shortest path
* Use postorder for bottom-up aggregation (e.g., LCA)
* Pay attention to null base cases

---

## Common Tree Problems

| Problem                          | Why Tree?                                 |
|----------------------------------|-------------------------------------------|
| Invert Binary Tree              | Swap children recursively                 |
| Validate BST                    | Enforce bounds via recursion              |
| Lowest Common Ancestor          | Bubble up results using postorder         |
| Diameter of Binary Tree         | Aggregate height from children            |
| Level Order Traversal           | BFS using queue                           |

---

## Tree Summary

Trees support recursive problem solving. Mastering DFS/BFS, traversal order, and node property logic is key for interviews.
