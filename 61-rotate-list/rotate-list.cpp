/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: empty list, single node, or no rotation needed
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* temp = head;
        int size = 0;

        // Count the number of nodes in the list
        while (temp->next != nullptr) {
            size++;
            temp = temp->next;
        }
        size++;  // Include the last node

        // Normalize k to avoid unnecessary full rotations
        k = k % size;
        if (k == 0)
            return head;

        // Connect the last node to the head to form a circular list
        temp->next = head;

        // Move (size - k) steps to find the new tail
        for (int i = 0; i < size - k; i++) {
            temp = temp->next;
        }

        // Set the new head and break the circle
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
