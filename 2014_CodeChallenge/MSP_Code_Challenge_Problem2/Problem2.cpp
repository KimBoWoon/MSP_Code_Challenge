#include <iostream>
#include <string>
using namespace std;

class Change_String
{
private:
	string str;
	void Change();
public:
	Change_String();
	void SetString();
	void PrintStar();
};
Change_String::Change_String() : str("")	{}
void Change_String::Change()
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
		else if (str[i] > 96 && str[i] < 123)
			str[i] -= 32;
	}
}
void Change_String::SetString()
{
	cout << "���ڿ��� �Է��ϼ���. : ";
	cin >> str;
}
void Change_String::PrintStar()
{
	Change();

	cout << "�ٲ� ���ڿ� : ";
	cout << str << endl;
}
int main()
{
	Change_String c;

	c.SetString();

	c.PrintStar();
}