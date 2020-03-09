#include <iostream>
#include <list>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

// 创建单链表
ListNode *creat() {
    ListNode *head, *temp;
    head = new ListNode;
    temp = head;

    int cycle = 5;
    while (cycle) {
        ListNode *s= new ListNode;
        s->data = cycle;
        temp->next = s;
        temp = s;
        cycle--;
    }
    head = head->next;
    temp->next = NULL;
    // cout << "head->data: " << head->data << endl;
    return head;
}

int lengthNode(ListNode* head) {
    int n = 0;
    ListNode *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        n++;
    }
    return n;
}

void printNode(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << " " << endl;
}

ListNode* insert(ListNode* head, int num) {
    ListNode *p0, *p1, *p2;
    p1 = head;
    p2 = new ListNode;
    p0 = new ListNode;
    p0->data = num;

    while (p0->data > p1->data && p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
    }
    if (p0->data <= p1->data) {
        if (p1 == head) {
            head = p0;
            p0->next = p1;
        } else {
            p2->next = p0;
            p0->next = p1;
        }
    } else {
        p1->next = p0;
        p0->next = NULL;
    }
    return head;
}

ListNode* deleteNode(ListNode* head, int num) {
    ListNode *p1, *p2;
    p2 = new ListNode;
    p1 = head;
    while (num != p1->data && p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->data) {
        if (p1 == head) {
            head = p1->next;
            delete p1;
        }
        else {
            p2->next = p1->next;
            delete p1;
        }
    } else {
        cout << "not found" << endl;
    }
    return head;
}


int main() {

    ListNode *head = creat();
    int length = lengthNode(head);
    // cout << length << endl;
    printNode(head);

    return 0;
}