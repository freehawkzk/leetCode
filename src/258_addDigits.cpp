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
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * For example:
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *
 * ����
 * ��Ŀ���⣺��һ�����ɶ�λ���ʱ�������ĸ�λ��ӣ�ֱ�����ֻ��һλ����ɣ������������
 * 
 * ˼·
 * 1����ͨ˼·������������Ӹ�λ��ѭ�����ɡ�
 * 2���������������ֽ�����й��ɣ�0.1.2.3.4.5.6.7.8.9.1.2.3.3.4.5.6.7.8.9.1.2.3.4.5������
 *    ���п��Կ��������ʵ������һ��9���Ƶ����У�������ͨ9���Ʋ�ͬ����ͨ9�����Ǵ�0-8��
 *    �����������1-9�����Կ��Ƕ�num%9���ʵ��ĵ�����
*/
/************************************************************************/
int addDigits(int num) {
	return 1 + (num - 1) % 9;
}

int main()
{
	int a = addDigits(18);
	return 0;
}