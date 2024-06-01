#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;
        ListNode dummy(0);
        dummy.next = head;

        ListNode* temp1;
        ListNode* temp2;
        ListNode* temp3;
        temp1 = &dummy;
        for (int i = 1; i < left; i++) {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        for (int i = 0; i < right - left; i++) {
            temp3 = temp2->next;
            temp2->next = temp3->next;
            temp3->next = temp1->next;
            temp1->next = temp3;
        }

        return dummy.next;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int left = 2, right = 4;
    ListNode* result = sol.reverseBetween(head, left, right);

    cout << "List after reversing between positions " << left << " and " << right << ": ";
    printList(result);

    ListNode* current = result;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
