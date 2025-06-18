## What Is DFS?

**Depth-First Search** = explore as far as possible down a branch before backtracking (last-in, first-out). Uses **recursion** or an **explicit stack**.

---

## When to Use DFS

* Explore all paths or combinations (backtracking)
* Traverse entire structures (e.g. trees, graphs)
* Solve problems involving hierarchy, recursion, or "choice trees"
* Detect cycles, topological sort, connected components

---

## Key DFS Patterns

### For Trees (Preorder/Postorder)

```cpp
void dfs(TreeNode* node) {
    if (node == nullptr) return;

    // process node (preorder)
    dfs(node->left);
    dfs(node->right);
    // process node (postorder)
}
```

### For Grids (Recursive DFS)

```cpp
void dfs(int x, int y) {
    if (out of bounds || grid[x][y] != targetVal) return;

    grid[x][y] = visitedMark;

    for (auto [dx, dy] : dirs) {
        dfs(x + dx, y + dy);
    }
}

vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
```

### For Graphs (Visited Set)

```cpp
void dfs(int node, unordered_set<int>& visited) {
    if (visited.count(node)) return;

    visited.insert(node);
    for (int neighbor : graph[node]) {
        dfs(neighbor, visited);
    }
}
```

---

## Tips to Remember

* Use recursion for tree/graph/grid DFS
* Track visited nodes (especially in graphs and grids)
* Use backtracking (undo state) when exploring combinations or paths
* Tree DFS doesn’t need visited if no cycles
* Preorder = process before recursion; Postorder = process after

---

## Common DFS Problems

| Problem                  | Why DFS?                              |
| ------------------------ | ------------------------------------- |
| Flood Fill               | Explore all connected cells           |
| Number of Islands        | Visit entire connected component      |
| Path Sum / Tree Problems | Explore paths and backtrack           |
| Word Search              | Try all paths through a grid          |
| Clone Graph              | Recursively copy each node & edges    |
| Detect Cycle in Graph    | Explore paths and detect revisits     |
| LCA of Binary Tree       | Post-order logic, bubbling up results |

---

## DFS Summary

Use DFS when you need to go deep — exploring all paths, making choices recursively, or evaluating subtrees. It’s ideal for traversal, backtracking, and divide-and-conquer patterns.
