#include <iostream>
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == 0)
        return 0;

    ListNode* p0 = head;
    ListNode* p1 = head;
    for (int i = 0; i < n - 1; i++)
        p1 = p1->next;
    ListNode* p2 = p0;
    if (p2->next == 0)
        return 0;
    if (p1->next == 0)
    {
        p2 = p2->next;
        return p2;
    }
    while (p1->next != 0)
    {
        p2 = p0;
        p0 = p0->next;
        p1 = p1->next;
    }
    p2->next = p0->next;
    return head;
}

int main()
{
    ListNode n0(0);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    int n = 1;
    ListNode* pHead = removeNthFromEnd(&n0, n);
    while (pHead )
    {
        std::cout << pHead->val << " ";
        pHead = pHead->next;
    }
    return 0;
}