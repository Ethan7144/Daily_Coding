## What Is Hashing?

**Hashing** uses key-value mapping for constant-time (O(1)) lookup, insertion, and deletion using a **hash map** or **hash set**.

---

## When to Use Hashing

* Track frequency of elements
* Count duplicates or uniques
* Group elements (e.g., by signature, frequency)
* Fast lookups (e.g., existence, index)

---

## Key Hashing Patterns

### Frequency Count

```cpp
unordered_map<int, int> freq;
for (int num : nums) {
    freq[num]++;
}

```

### Checking Uniqueness

```cpp
unordered_set<int> seen;
for (int num : nums) {
    if (seen.count(num)) return true;  // duplicate found
    seen.insert(num);
}
```

### Grouping + Collecting by Signature
```cpp
unordered_map<string, vector<string>> anagrams;
for (string& word : words) {
    string sig = word;
    sort(sig.begin(), sig.end());
    anagrams[sig].push_back(word);
}

vector<vector<string>> result;
for (auto& [sig, group] : anagrams) {
    result.push_back(group);
}
```

---

## Tips to Remember

* Use `unordered_map`/`unordered_set` for O(1) average ops
* Remember to initialize with default values if necessary
* Use `pair` keys or string keys carefully — define custom hash if needed

---

## Common Hashing Problems

| Problem                         | Why Hashing?                          |
| ------------------------------ | ------------------------------------- |
| Two Sum                        | Store seen numbers and indices        |
| Group Anagrams                 | Group words by sorted signature       |
| Top K Frequent Elements        | Count + sort or heap by frequency     |
| Longest Substring w/o Repeat   | Track last seen characters            |
| Happy Number                   | Detect cycle using set                |

---

## Hashing Summary

Hashing is your go-to tool when speed matters for lookups, counts, and membership. Think maps for counts and sets for uniqueness.


