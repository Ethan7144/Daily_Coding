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
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;
        
        ListNode *curr, *temp;
        temp = head;
        int size = 0;
        while(temp->next != nullptr){
            size++; 
            temp = temp->next;
        }size++;
        k = k % size;
        if(k == 0)
            return head;
        temp->next = head;
        for(int i = 0; i < size - k ; i++){
            temp = temp->next;
        }
            head = temp->next;
            temp->next = nullptr;

            return head;
        }

};