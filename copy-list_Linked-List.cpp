#include <iostream>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        curr = head;
        while (curr != nullptr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* newhead = head->next;
        while (curr != nullptr) {
            Node* temp = curr->next;
            curr->next = temp->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
            curr = curr->next;
        }
        return newhead;
    }
};

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << "Node value: " << curr->val;
        if (curr->random) {
            std::cout << ", Random value: " << curr->random->val;
        } else {
            std::cout << ", Random value: NULL";
        }
        std::cout << std::endl;
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    head->random = third;
    second->random = head;
    third->random = second;

    std::cout << "Original list:" << std::endl;
    printList(head);

    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    std::cout << "Copied list:" << std::endl;
    printList(copiedList);

    delete head;
    delete second;
    delete third;

    Node* temp;
    while (copiedList != nullptr) {
        temp = copiedList;
        copiedList = copiedList->next;
        delete temp;
    }

    return 0;
}
