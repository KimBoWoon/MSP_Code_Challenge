#include "Coin.h"

Coin::Coin()
{
	cout << "�Ž����� �Է�" << endl;
	cin >> coin;
}
void Coin::compute()
{
	int coin500 = 0, coin100 = 0, coin50 = 0, coin10 = 0, temp = 0;

	if (coin < 0)
	{
		cout << "����� " << abs(coin) << "������ ����� �����մϴ�." << endl;
		coin = abs(coin);
	}
	cout << "�Ž�����<���� ��>" << endl;
	while (true)
	{
		if (coin >= 500)
		{
			coin500++;
			coin -= 500;
			continue;
		}
		if (coin >= 100)
		{
			coin100++;
			coin -= 100;
			continue;
		}
		if (coin >= 50)
		{
			coin50++;
			coin -= 50;
			continue;
		}
		if (coin >= 10)
		{
			coin10++;
			coin -= 10;
			continue;
		}
		break;
	}
	cout << "500�� ���� : " << coin500 << endl;
	cout << "100�� ���� : " << coin100 << endl;
	cout << "50�� ���� : " << coin50 << endl;
	cout << "10�� ���� : " << coin10 << endl;
}