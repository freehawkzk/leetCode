#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int numJewelsInStones(string J, string S);
/************************************************************************/
/* 
 * ˼·
 * ����Ҫ����ַ���S��ͳ���ַ���J�������ַ����ֵĴ�����������Ŀ��֤�ַ���J��
 * �ַ����ֵĴ�����Ψһ�ģ���˲���Ҫ���ַ���J��������
 * 1�������������Ч���жϣ�
 * 2�����ַ���S��������ʹ�ַ�����������ͬ�ַ��������ģ�
 * 3�����������ַ����У�ͨ���������ַ���һ�γ���λ�ã�
 * 4�����������ַ����У�ͨ���Ҳ�����ַ���һ�γ���λ�ã�
 * 5����������λ��֮��+1��Ϊ���ַ����ֵĴ�����
 * 6���������ַ����ִ�����Ӽ��ɡ�
*/
/************************************************************************/
int numJewelsInStones(string J, string S) 
{
	//������Ч���ж�
	if (J.length() <= 0 || S.length() <= 0)
	{
		return 0;
	}
	//����S�ַ���
	sort(S.begin(), S.end());
	int nCount = 0;
	int nLeft = -1;
	int nRight = -1;
	for (int i = 0; i < J.length(); i++)//��S�в���J��ÿһ���ַ�
	{
		nLeft = S.find(J[i]);//������
		if (nLeft != std::string::npos)//����ҵ��ˣ��Ž����Ҳ�
		{
			nRight = S.rfind(J[i]);//�Ҳ����
			nCount += (nRight - nLeft + 1);//�ۼ��ַ���
			nRight = -1;//�ֳ�����
			nLeft = -1;//�ֳ�����
		}
	}

	return nCount;
}
int main()
{
	string J(" ");
	string S("azzAAZZ");
	int x = numJewelsInStones(J, S);
	return 0;
}