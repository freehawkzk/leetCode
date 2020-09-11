#include <vector>
#include <string>
#include <iostream>

using namespace std;
string intToRoman(int num);
string intToRoman(int num)
{
	//string vThousandStr[] = { "","M", "MM", "MMM" };
	//string vHundredStr[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	//string vTenStr[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	//string vStr[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	//string strResult;
	//strResult.append(vThousandStr[num / 1000]);
	//strResult.append(vHundredStr[num / 100 % 10]);
	//strResult.append(vTenStr[num / 10 % 10]);
	//strResult.append(vStr[num % 10]);
	//return strResult;


	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string numerals[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	string result;
	for (int i = 0; i < 13; i++) {
		while (num >= values[i]) {
			num -= values[i];
			result.append(numerals[i]);
		}
	}
	return result;
}
int main()
{
	int num = 999;
	
	string str = intToRoman(num);
	cout << str << endl;
	return 0;
}