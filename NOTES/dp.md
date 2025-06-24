
## What Is Dynamic Programming?

**Dynamic Programming (DP)** is an optimization technique to solve problems by breaking them down into overlapping subproblems and solving each subproblem only once.

---

## When to Use DP

* The problem has **overlapping subproblems**
* You can break the problem into smaller decisions
* The problem has **optimal substructure** (optimal solution built from optimal sub-solutions)

---

## Key DP Patterns (C++)

### 1D Tabulation (Bottom-Up)

```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
```

### Memoization (Top-Down)

```cpp
int dp[1000];
int fib(int n) {
    if (n <= 1) return n;
    if (dp[n]) return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}
```

### Kadane Algo
## Use for solving Maximum Subarray Sum problems

```cpp
int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0], currMax = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        currMax = max(nums[i], currMax + nums[i]);
        maxSoFar = max(maxSoFar, currMax);
    }
    return maxSoFar;
}
```


---

## Tips to Remember

* Start with recursion, then optimize with memo/table
* Use bottom-up tabulation for better space/time
* Recognize base cases early
* Use 2D arrays for knapsack/grid-based problems

---

## Common DP Problems

| Problem              | Why DP?                        |
|----------------------|--------------------------------|
| Climbing Stairs      | Overlapping subproblems        |
| House Robber         | Max sum with non-adjacent      |
| Coin Change          | Min coins to make amount       |
| Max Subarray         | Running max + Kadane’s         |
| 0/1 Knapsack         | Include/exclude logic          |

---

## DP Summary

Use DP when brute force recursion leads to repeated work. Optimize by storing solutions to subproblems.
