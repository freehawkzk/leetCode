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
 * Invert a binary tree.
 * 
 *       4
 *     /   \
 *    2     7
 *   / \   / \
 *  1   3 6   9
 * 
 * to
 * 
 *       4
 *     /   \
 *    7     2
 *   / \   / \
 *  9   6 3   1
 *
 * 分析
 * 题目要求交换树中的所有左右子树节点。
*/
/************************************************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
	{
		return NULL;
	}
	TreeNode* pT;
	pT = invertTree(root->right);
	root->right = invertTree(root->left);
	root->left = pT;
	return root;
}
int main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n6(6);
	TreeNode n7(7);
	TreeNode n9(9);

	n4.left = &n2;
	n4.right = &n7;

	n2.left = &n1;
	n2.right = &n3;

	n7.left = &n6;
	n7.right = &n9;
	TreeNode* pRoot = invertTree(&n4);
	return 0;
}