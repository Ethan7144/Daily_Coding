class Solution {
public:
    int romanToInt(string s) {
        // Mapping of Roman numerals to their integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;      // Final result
        int prev = 0;       // Value of the previous Roman symbol processed

        // Traverse the string from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            int curr = roman[s[i]];  // Current Roman value

            if (curr < prev) {
                // If the current value is smaller than the one after it,
                // subtract it (e.g., IV -> 5 - 1)
                total -= curr;
            } else {
                // Otherwise, add it normally
                total += curr;
            }

            // Update previous value for next iteration
            prev = curr;
        }

        return total;
    }
};
