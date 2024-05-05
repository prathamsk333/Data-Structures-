#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        
        ListNode *temp = head;
        ListNode *temp2 = head->next;
        
        while (temp != temp2) {
            if (temp2 == nullptr || temp2->next == nullptr) {
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next->next;
        }
        return true;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head;

    Solution sol;
    std::cout << std::boolalpha << sol.hasCycle(head) << std::endl;

    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
