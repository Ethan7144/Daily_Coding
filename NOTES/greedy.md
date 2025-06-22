
## What Is Greedy Algorithm?

A **Greedy Algorithm** builds up a solution piece-by-piece by always choosing the most immediate optimal choice. It does not revise decisions and works when local optimum leads to global optimum.

---

## When to Use Greedy

* You can make a local optimal choice and be confident it leads to a global optimum
* You're solving problems around intervals, resources, or tasks
* Sorting helps guide the decision-making process

---

## Key Greedy Patterns (C++)

### Merge Intervals

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0])
            merged.push_back(interval);
        else
            merged.back()[1] = max(merged.back()[1], interval[1]);
    }
    return merged;
}
```

### Meeting Rooms (Non-overlapping)

```cpp
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < intervals[i-1][1]) return false;
    }
    return true;
}
```

### Task Scheduling

```cpp
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char c : tasks) freq[c - 'A']++;
    sort(freq.begin(), freq.end());
    int maxFreq = freq[25] - 1;
    int idleSlots = maxFreq * n;
    for (int i = 24; i >= 0 && freq[i] > 0; --i) {
        idleSlots -= min(freq[i], maxFreq);
    }
    return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
}
```

---

## Tips to Remember

* Sort the input to guide decisions
* Watch for edge cases like overlap at boundaries
* Greedy won’t always work — compare with DP
* Justify why greedy works (prove correctness)

---

## Common Greedy Problems

| Problem              | Why Greedy?                             |
|----------------------|------------------------------------------|
| Merge Intervals      | Sort and combine overlapping intervals   |
| Insert Interval      | Insert and merge efficiently             |
| Meeting Rooms        | Conflict-free scheduling                 |
| Task Scheduler       | Fill idle slots around most frequent     |

---

## Greedy Summary

Greedy is about making the best immediate choice. It’s efficient and elegant — when it works. Validate if local choices lead to a global solution.
