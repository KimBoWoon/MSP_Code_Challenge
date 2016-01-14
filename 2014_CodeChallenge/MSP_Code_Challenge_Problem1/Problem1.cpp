#include <iostream>
using namespace std;

class Star
{
private:
	int num;
public:
	Star();
	void PrintStar() const;
};
Star::Star()
{
	while (1)
	{
		cout << "����� ���� �Է����ּ���. : ";
		cin >> num;

		if (num > 9 || num < 1)
			cout << "1~9������ ���ڷ� �ٽ� �Է����ּ���." << endl;
		else
			break;
	}
}
void Star::PrintStar() const
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j < num * i; j++)
			cout << "*";
		cout << endl;
	}
}
int main()
{
	Star s;

	s.PrintStar();
}