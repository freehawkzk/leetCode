#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;
/************************************************************************/
/*
 * Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
 * 
 * Example 1:
 * 
 * Input:
 *     1
 *    / \
 *   0   2
 * 
 * L = 1
 * R = 2
 * 
 * Output:
 *     1
 *      \
 *       2
 * 
 * Example 2:
 * 
 * Input:
 *     3
 *    / \
 *   0   4
 *    \
 *     2
 *    /
 *   1
 * 
 * L = 1
 * R = 3
 * 
 * Output:
 *     3
 *    /
 *   2
 *  /
 * 1
 * 分析
 * 题目要求对二叉搜索树进行裁剪，保留输入树中所有在指定区间内的节点，其余节点删除。
 * 二叉搜索树的性质：
 * 1、它可以是一棵空树；
 * 2、如果它的左子树不为空，那么左子树上所有节点值都小于该节点的值；
 * 3、如果它的右子树不为空，那么右子树上所有节点值都大于该节点的值；
 * 4、左子树和右子树也是搜索二叉树。
*/
/************************************************************************/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* trimBST(TreeNode* root, int L, int R) 
{
	if (root == NULL)//空树，返回空
		return NULL;

	if (root->val < L)//当前节点值小于区间左端点，返回裁剪过的右子树
	{
		return trimBST(root->right, L, R);
	}
	else if (root->val > R)//当前节点值大于区间右端点，返回裁剪过的左子树
	{
		return trimBST(root->left, L, R);
	}
	else
	{
		//当前节点的值在区间内，包括区间端点，分别对左子树和右子树进行裁剪
		root->left = trimBST(root->left, L, R);//裁剪左子树
		root->right = trimBST(root->right, L, R);//裁剪右子树
		return root;//返回根节点
	}
}
int main()
{
	TreeNode root(3);
	TreeNode n1(0);
	TreeNode n2(1);
	TreeNode n3(2);
	TreeNode n4(4);
	root.left = &n1;
	root.right = &n4;
	n1.left = NULL;
	n1.right = &n3;
	n3.left = &n2;
	n3.right = NULL;

	TreeNode* pRoot = trimBST(&root, 1, 3);
	
	return 0;
}