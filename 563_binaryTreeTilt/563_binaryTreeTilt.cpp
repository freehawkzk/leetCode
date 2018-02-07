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
 * Given a binary tree, return the tilt of the whole tree.
 * 
 * The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 * 
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 * 
 * Example:
 * 
 * Input:
 *    1
 *  /   \
 * 2     3
 * Output: 1
 * Explanation:
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 * 
 * Note:
 * 
 * The sum of node values in any subtree won't exceed the range of 32-bit integer.
 * All the tilt values won't exceed the range of 32-bit integer.
 * 
 * 分析
 * 1、树的Tilt由所有节点的tilt相加而成；
 * 2、节点的tilt通过左右子树所有节点和的差的绝对值组成；
 * 3、可以递归求解
*/
/************************************************************************/
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
int findSum(TreeNode* root)
{
	if (!root)
		return 0;
	return root->val + findSum(root->left) + findSum(root->right);
}

int findTilt(TreeNode* root) {
	if (!root)
		return 0;
	int nTilt = 0;
	nTilt = abs(findSum(root->left) - findSum(root->right));
	nTilt = nTilt + findTilt(root->left) + findTilt(root->right);
	return nTilt;
}
int main()
{

	return 0;
}