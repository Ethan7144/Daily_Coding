## What Is BFS?
Breadth-First Search = visit nodes level by level (first-in, first-out) using a queue.

## When to Use BFS
- Find shortest path in unweighted graphs or grids
- Explore all connected components
- Solve flood fill, spreading, or level-based problems

## Key BFS Pattern

### For Trees (Level Order)
```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    TreeNode* node = q.front(); q.pop();
    // process node
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
}
```
### For Grids (Matrix BFS)
```cpp
queue<pair<int, int>> q;
q.push({startX, startY});
grid[startX][startY] = visitedMark;

vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (in bounds && grid[nx][ny] == targetVal) {
            grid[nx][ny] = visitedMark;
            q.push({nx, ny});
        }
    }
}
```
## Tips to Remember
- Use a queue: push when discovering, pop to explore
- Mark visited when pushing to the queue (not when popping)
- Use direction arrays for cleaner neighbor logic in grids
- Tree BFS doesn't need visited set (no cycles)

## Common BFS Problems

| Problem             | Why BFS?                        |
|---------------------|----------------------------------|
| Number of Islands   | Find all connected '1's         |
| Surrounded Regions  | Border-connected 'O' search     |
| Word Ladder         | Shortest transformation         |
| Minimum Depth       | First leaf node found           |
| Flood Fill          | Spread across same-color area   |

## BFS Summary
Use BFS when you need to explore outward in waves — for shortest path, level order traversal, or any "spread" type of problem.
