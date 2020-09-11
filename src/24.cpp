#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

ListNode* swapPairs(ListNode* head)
{
    if (head == 0)
        return head;
    if (head->next == 0)
        return head;
    ListNode* p0 = head;
    ListNode* pTail = head;
    while (p0 && p0->next)
    {
        ListNode* p1 = p0->next;
        ListNode* p2 = p1->next;

        pTail->next = p1;
        p1->next = p0;
        pTail = p0;
        p0->next = p2;
        p0 = p2;
        if (pTail==head)
        {
            head = p1;
        }
    }

    return head;
}

int main()
{
    ListNode n00(0);
    ListNode n01(1); n00.next = &n01;
    ListNode* phead = swapPairs(&n00);
    while (phead != 0)
    {
        std::cout << phead->val << std::endl;
        phead = phead->next;
    }
    return 0;
}