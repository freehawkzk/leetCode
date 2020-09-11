#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL || l2 == NULL)
	{
		if (!l1 )
		{
			return l2;
		}
		else if (!l2)
		{
			return l1;
		}
		return NULL;
	}

	ListNode* pResult = l1;
	ListNode* l1Tail = NULL;
	int nNeedAddOne = 0;
	while (l1 && l2)
	{
		l1->val = l1->val + l2->val + nNeedAddOne;
		if (l1->val >= 10)
		{
			l1->val -= 10;
			nNeedAddOne = 1;
		}
		else
			nNeedAddOne = 0;

		if (l1->next == NULL)
		{
			l1Tail = l1;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	if (!l1 && !l2 && nNeedAddOne == 1)
	{
		ListNode* temp = new ListNode(nNeedAddOne);
		l1Tail->next = temp;
	}
	if ((!l1) && l2)
	{
		l1Tail->next = l2;
		l1 = l2;
	}

	while (l1)
	{
		l1->val = l1->val + nNeedAddOne;
		if (l1->val >= 10)
		{
			l1->val -= 10;
			nNeedAddOne = 1;
		}
		else
			nNeedAddOne = 0;
		if (l1->next == NULL)
		{
			l1Tail = l1;
		}
		l1 = l1->next;
	}
	if (!l1  && nNeedAddOne == 1)
	{
		ListNode* temp = new ListNode(nNeedAddOne);
		l1Tail->next = temp;
	}
	return pResult;
}

int main()
{
	ListNode* l1 = NULL; 
	ListNode* l1Head = NULL;
	ListNode* l2 = NULL;
	ListNode* l2Head = NULL;
	int valInL1[] = { 5 };
	int valInL2[] = { 5 ,9 ,9};

	int nL1 = sizeof(valInL1) / sizeof(valInL1[0]);
	int nL2 = sizeof(valInL2) / sizeof(valInL2[0]);
	for (int i = 0; i < nL1; i++)
	{
		ListNode* temp = new ListNode(valInL1[i]);
		if (i == 0 )
		{
			l1 = temp;
			l1Head = l1;
		}
		else
		{
			l1->next = temp;
			l1 = l1->next;
		}
	}

	for (int i = 0; i < nL2; i++)
	{
		ListNode* temp = new ListNode(valInL2[i]);
		if (i == 0)
		{
			l2 = temp;
			l2Head = l2;
		}
		else
		{
			l2->next = temp;
			l2 = l2->next;
		}
	}

	ListNode* pResult = addTwoNumbers(l1Head, l2Head);
	while (pResult)
	{
		cout << pResult->val << endl;
		pResult = pResult->next;
	}
	return 0;
}