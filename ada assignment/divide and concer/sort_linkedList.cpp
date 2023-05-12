/*Ques: Implement a divide-and-conquer algorithm for sorting a linked list.*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists.
ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to divide the linked list into two halves.
ListNode* divide(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = NULL;
    return slow;
}

// Function to sort the linked list using divide-and-conquer algorithm.
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* mid = divide(head);
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(mid);
    return merge(l1, l2);
}

// Function to print the linked list.
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Test the implementation.
int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    cout << "Original list: ";
    printList(head);
    head = sortList(head);
    cout << "Sorted list: ";
    printList(head);
    return 0;
}
