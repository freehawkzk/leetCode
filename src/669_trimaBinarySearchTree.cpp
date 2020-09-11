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
 * ����
 * ��ĿҪ��Զ������������вü���������������������ָ�������ڵĽڵ㣬����ڵ�ɾ����
 * ���������������ʣ�
 * 1����������һ�ÿ�����
 * 2�����������������Ϊ�գ���ô�����������нڵ�ֵ��С�ڸýڵ��ֵ��
 * 3�����������������Ϊ�գ���ô�����������нڵ�ֵ�����ڸýڵ��ֵ��
 * 4����������������Ҳ��������������
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
	if (root == NULL)//���������ؿ�
		return NULL;

	if (root->val < L)//��ǰ�ڵ�ֵС��������˵㣬���زü�����������
	{
		return trimBST(root->right, L, R);
	}
	else if (root->val > R)//��ǰ�ڵ�ֵ���������Ҷ˵㣬���زü�����������
	{
		return trimBST(root->left, L, R);
	}
	else
	{
		//��ǰ�ڵ��ֵ�������ڣ���������˵㣬�ֱ�������������������вü�
		root->left = trimBST(root->left, L, R);//�ü�������
		root->right = trimBST(root->right, L, R);//�ü�������
		return root;//���ظ��ڵ�
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