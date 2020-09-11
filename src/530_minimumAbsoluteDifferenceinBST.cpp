#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
using namespace std;
/************************************************************************/
/*
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
 *
 * Example:
 *
 * Input:
 *
 * 1
 *  \
 *   3
 *  /
 * 2
 *
 * Output:
 * 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 *
 * Note: There are at least two nodes in this BST.
 *
 * ����
 * ��һ�ö��������������нڵ�֮��ľ���ֵ����Сֵ��
 *
 * ˼·
 * ����������������ת�������飬������⡣
 *
 * ע��
 * ��˼·ֻ�ܱ�֤����������Ч�ʺܵ͡�
*/
/************************************************************************/
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
vector<TreeNode*> vNodes;
int nMin = INT_MAX;
int getMinimumDifference(TreeNode* root) 
{
	if (!root)
	{
		return 0;
	}

	for (const TreeNode* pN : vNodes)
	{
		int nTemp = abs(pN->val - root->val);
		if (nMin >nTemp)
		{
			nMin = nTemp;
		}
	}
	vNodes.push_back(root);
	getMinimumDifference(root->left);
	getMinimumDifference(root->right);

	return nMin;
}

int main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	n1.right = &n3;
	n3.left = &n2;
	int n = getMinimumDifference(&n1);
	return 0;
}