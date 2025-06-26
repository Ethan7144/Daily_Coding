/*
Summary:
---------
This solution finds the length of the longest subsequence of a binary string `s`
that represents a binary number less than or equal to a given integer `k`.

Problem Assumptions:
- The subsequence can contain leading zeros.
- You can remove characters (but not reorder them) to form the subsequence.
- The empty string is valid and equals 0.

Approach:
- Traverse the string from right to left (least significant bit first).
- Always include '0's: they extend the subsequence length without increasing the value.
- Include '1's only if including them keeps the binary value ≤ k.
- The value is built bit-by-bit from the right (1 << bit position).
- We limit the number of bits considered to the maximum bit length of `k`
  to avoid overflow and unnecessary checks.

Time Complexity: O(n) — single pass through the string
Space Complexity: O(1) — constant extra space (just counters and accumulators)
*/

class Solution {
public:
    int longestSubsequence(const string& s, int k) {
        int n = s.size();
        int res = 0;
        long long cur = 0;

        // Calculate the number of bits needed to represent k
        int maxBits = 0;
        for (int x = k; x > 0; x >>= 1) ++maxBits;

        // Traverse from least significant bit (rightmost) to most
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];

            if (c == '0') {
                // Always safe to include zero
                ++res;
            } 
            else if (res < maxBits) {
                // Try including '1' if the resulting value stays <= k
                long long added = 1LL << res;
                if (cur + added <= k) {
                    cur += added;
                    ++res;
                }
            }
        }

        return res;
    }
};
