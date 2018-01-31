/************************************************************************/
/* 
 * 
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 * 
 * Example 1:
 * 
 * Input:
 * Tree 1                     Tree 2
 *      1                         2
 *     / \                       / \
 *    3   2                     1   3
 *   /                           \   \
 *  5                             4   7
 * Output:
 * Merged tree:
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  5   4   7
 * 
 * Note: The merging process must start from the root nodes of both trees.
 * 思路
 * 本题要求合并两棵树，合并规则
 * 1、 对应位置都不为空的节点，将节点值置为两者之和；
 * 2、 有一个为空的节点，将节点置为不为空的节点；
 * 3、 从根节点开始比较。
 * 对于树等结构，通常采用递归的方式进行处理。
 * 采用前序遍历的方式遍历树，即先处理当前节点，再处理它的左子树，再处理它的右子树。
*/
/************************************************************************/


 //Definition for a binary tree node.
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 != NULL && t2 != NULL)
		{
			t1->val += t2->val;
			t1->left = mergeTrees(t1->left, t2->left);
			t1->right = mergeTrees(t1->right, t2->right);
			return t1;
		}
		else if (t1 == NULL && t2 != NULL)
		{
			return t2;
		}
		else if (t1 != NULL && t2 == NULL)
		{
			return t1;
		}
		else
			return NULL;

	}
};