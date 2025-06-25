
## Sliding Window (Fixed and Variable Size)

```cpp
// Fixed-Size
for (int i = 0; i < nums.size(); ++i) {
    windowSum += nums[i];
    if (i >= k) windowSum -= nums[i - k];
    if (i >= k - 1) res = max(res, windowSum);
}

// Variable-Size
int left = 0;
for (int right = 0; right < s.size(); ++right) {
    // Expand window
    while (/* invalid condition */) {
        // Shrink window
        left++;
    }
    res = max(res, right - left + 1);
}
```

## Two Pointers

```cpp
// Opposite direction (sorted array, palindromes)
int left = 0, right = nums.size() - 1;
while (left < right) {
    if (/* condition */) return true;
    else if (/* adjust */) left++;
    else right--;
}

// Same direction (fast/slow or overwrite)
int slow = 0;
for (int fast = 0; fast < nums.size(); ++fast) {
    if (/* keep condition */) nums[slow++] = nums[fast];
}
```

## DFS / Backtracking

```cpp
void dfs(int node, unordered_set<int>& visited) {
    if (visited.count(node)) return;
    visited.insert(node);
    for (int neighbor : graph[node]) dfs(neighbor, visited);
}

void backtrack(vector<int>& path) {
    if (/* base case */) res.push_back(path);
    for (int i = 0; i < choices.size(); ++i) {
        path.push_back(choices[i]);
        backtrack(path);
        path.pop_back();  // undo
    }
}
```

## BFS (Queue)

```cpp
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
```

## Binary Search

```cpp
int left = 0, right = nums.size() - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

## Prefix Sum + HashMap

```cpp
unordered_map<int, int> seen = {{0, -1}};
int sum = 0, maxLen = 0;
for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    if (seen.count(sum)) maxLen = max(maxLen, i - seen[sum]);
    else seen[sum] = i;
}
```

## Min/Max Heap (Top K Elements)

```cpp
priority_queue<int, vector<int>, greater<>> minHeap;
for (int num : nums) {
    minHeap.push(num);
    if (minHeap.size() > k) minHeap.pop();
}
// Top-K are in heap
```
