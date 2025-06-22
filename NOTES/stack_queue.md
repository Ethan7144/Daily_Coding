
## What Are Stacks and Queues?

**Stack** = Last In First Out (LIFO)  
**Queue** = First In First Out (FIFO)  
They are fundamental data structures for tracking order and processing elements sequentially.

---

## When to Use

* **Stack**: Reversal, backtracking, undo behavior
* **Queue**: BFS traversal, sliding window, stream processing
* Use **deque** for sliding window and monotonic stack

---

## Stack / Queue Patterns (C++)

### Valid Parentheses (Stack)

```cpp
bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> pairs = {{')','('}, {']','['}, {'}','{'}};
    for (char c : s) {
        if (pairs.count(c)) {
            if (stk.empty() || stk.top() != pairs[c]) return false;
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.empty();
}
```

### Monotonic Stack (Next Greater)

```cpp
vector<int> nextGreater(vector<int>& nums) {
    stack<int> stk;
    vector<int> res(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++) {
        while (!stk.empty() && nums[i] > nums[stk.top()]) {
            res[stk.top()] = nums[i];
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}
```

---

## Tips to Remember

* Stack for reversal, nested structure
* Queue/Deque for level traversal or window ops
* Use deque for max/min sliding window in O(n)

---

## Common Stack/Queue Problems

| Problem                     | Why Stack/Queue?                      |
|----------------------------|----------------------------------------|
| Valid Parentheses          | Balanced expression check             |
| Trapping Rain Water        | Use stack to calculate trapped height |
| Sliding Window Maximum     | Monotonic deque                       |
| Min Stack                  | Track min with auxiliary stack        |
| Level Order Traversal      | Use queue to process levels           |

---

## Stack/Queue Summary

These structures are vital for managing order — stacks for nested flow and queues for sequencing or window control.
