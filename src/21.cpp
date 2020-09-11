#include<iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == 0)
        return l2;
    if (l2 == 0)
        return l1;

    ListNode* pHead = l1;
    if (l1->val > l2->val)
    {
        pHead = l2;
    }
    ListNode* pl1 = l1;
    ListNode* pl2 = l2;
    ListNode* pTail = pHead;
    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            while (l2->next && l2->next->val <= l1->val)
            {
                l2 = l2->next;
            }
            pl2 = l2->next;
            l2->next = l1;
            pTail = l1;
            l2 = pl2;
        }
        else
        {
            while (l1->next && l1->next->val <= l2->val)
            {
                l1 = l1->next;
            }
            pl1 = l1->next;
            l1->next = l2;
            pTail = l2;
            l1 = pl1;
        }
    }
    if (l1 == 0 && l2 != 0 && pTail != l2)
        pTail->next = l2;
    if (l1 != 0 && l2 == 0 && pTail != l1)
        pTail->next = l1;
    return pHead;
}


int main()
{
    ListNode n00(0);
    ListNode n01(2); n00.next = &n01;
    ListNode n02(4); n01.next = &n02;
    ListNode n03(5); n02.next = &n03;
    ListNode n04(5); n03.next = &n04;
    ListNode n10(1);
    ListNode n11(1); n10.next = &n11;
    ListNode n12(3); n11.next = &n12;
    ListNode n13(4); n12.next = &n13;
    ListNode n14(5); n13.next = &n14;
    ListNode n15(6); n14.next = &n15;
    ListNode n16(8); n15.next = &n16;

    ListNode* phead = mergeTwoLists(&n00, &n10);
    while (phead != 0)
    {
        std::cout << phead->val << std::endl;
        phead = phead->next;
    }
    return 0;
}