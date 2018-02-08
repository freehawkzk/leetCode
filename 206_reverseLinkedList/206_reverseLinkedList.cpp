#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/************************************************************************/
/*
 * Reverse a singly linked list.
*/
/************************************************************************/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

ListNode* reverseList(ListNode* head)
{
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* pNext = head->next;
	ListNode* pNext2 = nullptr;
	head->next = nullptr;
	while (pNext->next)
	{
		pNext2 = pNext->next;
		pNext->next = head;
		head = pNext;
		pNext = pNext2;
	}
	pNext->next = head;
	head = pNext;
	return head;
}

int main()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	ListNode* pH = reverseList(&n1);
	return 0;
}