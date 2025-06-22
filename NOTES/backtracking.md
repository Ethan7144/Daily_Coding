
## What Is Backtracking?

**Backtracking** is a form of recursion used to solve problems incrementally by trying all possible solutions and undoing ("backtracking") when a path fails.

---

## When to Use Backtracking

* You're solving "all combinations", "all permutations", "subset" type problems
* You need to explore multiple decision paths
* You want to construct solutions incrementally and abandon invalid paths early

---

## Core Concepts

* **Decision Tree**: Backtracking explores a tree of choices
* **Pruning**: Skip unnecessary paths early to reduce time
* **Backtrack Step**: Undo the last choice to try another

---

## Key Backtracking Patterns (C++)

### Subsets (All Combinations)

```cpp
void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backtrack(nums, i + 1, path, res);
        path.pop_back(); // undo
    }
}
```

### Permutations (Order Matters)

```cpp
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, used, path, res);
        path.pop_back();
        used[i] = false;
    }
}
```

### Word Search (2D Grid)

```cpp
bool backtrack(vector<vector<char>>& board, string word, int i, int j, int k) {
    if (k == word.size()) return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
        return false;
    char tmp = board[i][j];
    board[i][j] = '#';
    bool found = backtrack(board, word, i+1,j,k+1) || backtrack(board, word, i-1,j,k+1) ||
                 backtrack(board, word, i,j+1,k+1) || backtrack(board, word, i,j-1,k+1);
    board[i][j] = tmp;
    return found;
}
```

---

## Tips to Remember

* Always undo the last step (`pop_back`, `used[i] = false`)
* Prune paths early (e.g., skip duplicates, target < 0)
* For combinations: use `start` index to avoid reuse
* For permutations: use `visited` or modify in-place

---

## Common Backtracking Problems

| Problem             | Why Backtracking?                        |
|---------------------|-------------------------------------------|
| Subsets             | All combinations without repeats          |
| Permutations        | All unique orderings                      |
| Combination Sum     | All ways to reach target                  |
| Word Search         | Pathfinding in 2D grid                    |
| N-Queens            | Placement with constraints                |

---

## Backtracking Summary

Backtracking is recursion + choice + undo. Ideal for problems requiring **all possible paths**, **constraint satisfaction**, or **combinatorics**.
