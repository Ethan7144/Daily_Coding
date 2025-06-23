/**
 * Problem: Generate Parentheses (Leetcode 22)
 *
 * Description:
 * Given an integer n, generate all combinations of n pairs of valid parentheses.
 *
 * Approach:
 * - Use backtracking to recursively build valid parentheses strings.
 * - Maintain two counters:
 *     - `open`: number of '(' used so far
 *     - `close`: number of ')' used so far
 * - Constraints:
 *     - You can add '(' if open < n
 *     - You can add ')' if close < open (to ensure valid structure)
 * - Once the current string length reaches 2 * n, it's a complete valid combination.
 *
 * Time Complexity: O(2^n)
 *   - Each decision point branches, but pruning avoids invalid paths.
 *
 * Space Complexity: O(n)
 *   - Maximum recursion depth and string construction.
 *
 * Pattern: Backtracking with pruning
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

    void backtrack(vector<string>& res, string curr, int open, int close, int max) {
        if (curr.length() == max * 2) {
            res.push_back(curr);
            return;
        }
        if (open < max) {
            backtrack(res, curr + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(res, curr + ")", open, close + 1, max);
        }
    }
};
