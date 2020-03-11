#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reverseNode(ListNode* &node) {
    ListNode** head = &node;
    ListNode** pivot = &(*head)->next;
    while (*pivot) {
        swap(*head, (*pivot)->next);
        swap(*head, *pivot);
    }
}