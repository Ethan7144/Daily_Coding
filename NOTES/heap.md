## What Is a Heap?

A **heap** is a binary tree-based structure used to efficiently retrieve the **smallest** or **largest** element. In C++, this is implemented using `priority_queue`.

By default, C++'s `priority_queue` is a **max-heap**.

---

## When to Use a Heap

* Track the K largest or smallest elements
* Continuously get min or max in a data stream
* Sort elements dynamically by custom priority

---

## Key Heap Patterns (C++)

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(num);
minHeap.pop();
int smallest = minHeap.top();
```

### Max Heap (default)

```cpp
priority_queue<int> maxHeap;
maxHeap.push(num);
maxHeap.pop();
int largest = maxHeap.top();
```

### Heaps of Pairs (Min By First)

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
pq.push({priority, value});
```
---

## Tips to Remember

* Use `greater<>` to make a min-heap
* For top K frequent, use a **min-heap of size K**
* For closest points, push pairs of (distance, point)
* Always pop when size exceeds K to maintain heap size

---

## Common Heap Problems

| Problem                   | Why Heap?                                 |
| ------------------------- | ------------------------------------------ |
| Top K Frequent Elements   | Track top K using min-heap by frequency    |
| K Closest Points to Origin| Heap by distance                           |
| Find Median from Stream   | Two heaps (maxHeap + minHeap)              |
| Merge K Sorted Lists      | Min-heap of current heads of each list     |

---

## Heap Summary

Heaps help manage dynamic data where you need fast access to the minimum or maximum. Use them when dealing with **top-K**, **priority**, or **streaming problems**.
