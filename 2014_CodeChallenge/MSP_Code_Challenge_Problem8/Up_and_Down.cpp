#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int random, user = -1, cnt = 0;

	srand(time(NULL));
	random = rand() % 50;

	cout << "0~50 ������ ���� �Է����ּ���." << endl;
	while (random != user && cnt < 10)
	{
		cin >> user;
		if (user > 50 || user < 0)
		{
			cout << "0���� 50������ ���ڸ� �Է����ּ���" << endl;
			continue;
		}
		if (user == random)
			break;
		if (user > random)
			cout << "���亸�� ū ���� �ԷµǾ����ϴ�!" << endl << "�ٽ� �Է����ּ���" << endl;
		else
			cout << "���亸�� ���� ���� �ԷµǾ����ϴ�!" << endl << "�ٽ� �Է����ּ���" << endl;
		cnt++;
	}
	if (cnt == 10)
		cout << "�õ� ����Ƚ���� �ʰ��߽��ϴ�." << endl;
	else
		cout << cnt + 1 << "��°�� �����߽��ϴ�!" << endl;
}