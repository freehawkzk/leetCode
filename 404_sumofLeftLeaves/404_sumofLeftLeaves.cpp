#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;
/************************************************************************/
/*
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 * 
 * 分析
 * 计算整棵树所有左叶子节点的和
*/
/************************************************************************/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

int sumOfLeftLeaves(TreeNode* root) {
	if (!root)
		return 0;
	int sum = 0;
	if (root->left && !(root->left->left) && !(root->left->right))
	{
		sum = sum + root->left->val;

	}
	sum = sum + sumOfLeftLeaves(root->left);
	sum = sum + sumOfLeftLeaves(root->right);
	return sum;
}
int main()
{

	return 0;
}