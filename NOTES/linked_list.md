## What Is a Linked List?

A **linked list** is a linear data structure where each element (node) points to the next. It’s useful for dynamic memory and fast insertions/deletions without shifting elements.

---

## When to Use Linked Lists

* Insert or delete elements in O(1) without shifting
* Track relationships via pointers
* Reverse or traverse structures dynamically
* Work with problems involving node-to-node connections

---

## Key Linked List Patterns (C++)

### Reverse a Linked List (Iterative)

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
```

### Detect Cycle (Floyd's Tortoise and Hare)

```cpp
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

```

### Merge two sorted List
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy, *tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```

---

## Tips to Remember

* Use dummy nodes to simplify head insertions
* Track both current and previous pointers for mutations
* Use fast/slow pointers for middle or cycle detection
* Don’t forget to `nullptr`-terminate lists when manipulating

---

## Common Linked List Problems

| Problem                     | Why Linked List?                         |
|----------------------------|-------------------------------------------|
| Reverse a Linked List      | In-place pointer reversal                 |
| Merge K Sorted Lists       | Repeated merging, use min-heap            |
| Detect Cycle               | Fast/slow pointer loop detection          |
| Remove N-th Node from End  | Use 2 pointers separated by N steps       |
| Intersection of Two Lists  | Track tail sync or use length difference  |

---

## Linked List Summary

Linked lists are ideal for dynamic structures where direct memory pointers help with flexibility. They’re key in problems with sequence mutation, cycle detection, and merging logic.

