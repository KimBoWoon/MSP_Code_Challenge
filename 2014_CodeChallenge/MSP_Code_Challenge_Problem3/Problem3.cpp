#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Bracket
{
private:
	string str;
public:
	Bracket();
	bool BracketBalance();
};
Bracket::Bracket()
{
	cout << "�ڵ� �� ��(80�� �̳�)�� �Է����ּ���." << endl;
	cin >> str;
}
bool Bracket::BracketBalance()
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else
		{
			if (s.empty())
				return false;
			if (s.top() == '(')
				s.pop();
		}
	}
	if (!(s.empty()))
		return false;
	else
		return true;
}
int main()
{
	Bracket b;

	if (b.BracketBalance())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}