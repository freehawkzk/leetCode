#include<iostream>
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
ListNode* reverseKGroup(ListNode* head, int k)
{
    if (!head)
        return head;
    if (!head->next)
        return head;
    if (k <= 1)
        return head;

    std::vector<ListNode*> pks(k, 0);
    ListNode* pTail = head;
    ListNode* p0 = head;
    while (p0)
    {
        int i = 0;
        for (; i < k&&p0; i++)
        {
            pks[i] = p0;
            p0 = p0->next;
        }
        if (i == k)
        {
            pTail->next = pks[pks.size() - 1];
            for (int j = pks.size() - 1; j >= 1; j--)
            {
                pks[j]->next = pks[j - 1];
            }
            if (pTail == head)
            {
                head = pks[pks.size() - 1];
            }
            pTail = pks[0];
            pks[0]->next = p0;
        }
        else
        {
            if (pTail != head)
                pTail->next = pks[0];
        }
    }
    return head;
}

int main()
{
    ListNode n00(0);
    ListNode n01(1); n00.next = &n01;
    ListNode n02(4); n01.next = &n02;
    //ListNode n03(5); n02.next = &n03;
    //ListNode n04(5); n03.next = &n04;
    //ListNode n10(1); n04.next = &n10;
    //ListNode n11(1); n10.next = &n11;
    //ListNode n12(3); n11.next = &n12;
    //ListNode n13(4); n12.next = &n13;
    //ListNode n14(5); n13.next = &n14;
    //ListNode n15(6); n14.next = &n15;
    //ListNode n16(8); n15.next = &n16;
    int k = 4;
    ListNode* phead = reverseKGroup(&n00, k);
    while (phead != 0)
    {
        std::cout << phead->val << std::endl;
        phead = phead->next;
    }
    return 0;
}