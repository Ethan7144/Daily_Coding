/*
 * Concept: Two Pointers
 *
 * Goal:
 * Efficiently traverse a string or array from two directions or at two speeds to solve problems in linear time.
 *
 * When to Use:
 * - Checking symmetry (palindromes)
 * - Finding pairs (e.g., two sum in sorted array)
 * - Modifying arrays in-place (removing/partitioning elements)
 * - Finding duplicates or cycles (linked lists, arrays)
 *
 * Common Patterns:
 *
 * 1. Opposite Direction (start from both ends):
 *    - Use when comparing or narrowing inward from both sides
 *    - Typical in palindrome checks, pair sums, or when skipping characters
 *
 * 2. Same Direction (read-write or fast-slow):
 *    - Use when overwriting in-place or scanning with constraints
 *    - Useful for partitioning, compaction, or finding cycles/midpoints
 *
 * Time Complexity: O(n)
 *   - Each pointer typically moves once per element
 *
 * Space Complexity: O(1)
 *   - Operates in-place using just pointer variables
 *
 * Tips:
 * - Watch for off-by-one errors (`left < right` vs `left <= right`)
 * - Combine with sorting or hashing when necessary
 * - Be careful with edge cases: empty input, single element, bounds checking
 */

// Opposite-direction two pointers
bool processOppositeDirection(const string& s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (/* condition fails */) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Same-direction two pointers
int processSameDirection(vector<int>& nums) {
    int write = 0;
    for (int read = 0; read < nums.size(); ++read) {
        if (/* condition to keep nums[read] */) {
            nums[write++] = nums[read];
        }
    }
    return write;
}

// Fast and slow pointer (e.g., finding cycles or midpoints)
bool processFastSlow(const vector<int>& nums) {
    int slow = 0, fast = 0;
    while (fast < nums.size() && fast + 1 < nums.size()) {
        slow++;
        fast += 2;
        if (/* condition involving slow and fast */) {
            return true;
        }
    }
    return false;
}

//  Expand Around Cetner
pair<int, int> expandFromCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return the final indices of the palindrome substring
    // Note: we expanded one too far on both sides
    return {left + 1, right - 1};
}