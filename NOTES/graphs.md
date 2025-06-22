
## What Are Graphs?

A **graph** is a set of nodes (vertices) connected by edges. They may be directed or undirected, weighted or unweighted.

---

## When to Use Graphs

* Problems involving connectivity, traversal, or relationships
* Grids (2D BFS/DFS) are special cases of graphs
* Cycle detection, shortest path, and components

---

## Graph Traversal Patterns (C++)

### DFS (Recursive)

```cpp
void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
    if (visited.count(node)) return;
    visited.insert(node);
    for (int neighbor : graph[node])
        dfs(neighbor, graph, visited);
}
```

### BFS (Queue)

```cpp
void bfs(int start, unordered_map<int, vector<int>>& graph) {
    queue<int> q;
    unordered_set<int> visited;
    q.push(start); visited.insert(start);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
```

---

## Tips to Remember

* Use BFS for shortest path (unweighted)
* DFS for exploring deeply, cycle detection
* Use grid-to-graph conversion for 2D problems
* Visited set/array prevents infinite loops

---

## Common Graph Problems

| Problem              | Why Graph?                               |
|----------------------|-------------------------------------------|
| Number of Islands    | Connected components via DFS/BFS          |
| Rotting Oranges      | BFS to model spread over time             |
| 01 Matrix            | BFS for shortest distance                 |
| Clone Graph          | DFS + map to recreate structure           |
| Course Schedule      | Topological sort + cycle detection        |

---

## Graph Summary

Graphs are essential for understanding networks, paths, and connectivity. Use BFS and DFS wisely for structure and efficiency.
