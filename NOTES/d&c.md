```cpp
ReturnType divideAndConquer(InputType input) {
    // Base case
    if (baseCondition(input)) {
        return baseResult(input);
    }

    // Divide
    auto [left, right] = split(input);

    // Conquer
    ReturnType leftResult = divideAndConquer(left);
    ReturnType rightResult = divideAndConquer(right);

    // Combine
    return combine(leftResult, rightResult);
}

```
divide and conquer format

longest substring with k repeats

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int longestSubstring(string s, int k) {
    if (s.empty()) return 0;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (freq[s[i]] < k) {
            // Divide at the invalid character
            int left = longestSubstring(s.substr(0, i), k);
            int right = longestSubstring(s.substr(i + 1), k);
            return max(left, right);
        }
    }

    // All characters are valid
    return s.length();
}
```