#include "Anagram.h"

int main()
{
	char c[2] = { 'y' };

	while (c[0] == 'y' || c[0] == 'Y')
	{
		cout << "ù ��° ���ڿ��� �Է��ϼ���" << endl;
		Anagram str1;
		cout << "�� ��° ���ڿ��� �Է��ϼ���" << endl;
		Anagram str2;

		if (str1 == str2)
			cout << "�Ƴ��׷� �´�" << endl;
		else
			cout << "�Ƴ��׷� �ƴϴ�" << endl;

		cout << "��� �����Ͻðڽ��ϱ�? (y/n)" << endl;
		cin.getline(c, 2);
	}
}