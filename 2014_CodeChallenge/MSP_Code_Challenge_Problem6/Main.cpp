#include "Accumulated_Money.h"

int main()
{
	BankBalance bb;
	AccumulatedMoney am;
	int Money, AMMoney;
	char cur;

	bb.PrintMoney();
	cout << ", ";
	am.PrintMoney();
	cout << endl << endl;

	while (true)
	{
		cout << "�����Ͻ� ������ ���� : ";
		cin >> Money;
		if (Money > bb.GetMoney())
		{
			cout << "���� ���� �ܰ� �����մϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		cout << "�������� ����Ͻðڽ��ϱ�? (y/n) : ";
		cin >> cur;
		cout << endl;
		if (cur == 'y')
		{
			cout << "����Ͻ� �������� �Է����ּ���. : ";
			while (true)
			{
				cin >> AMMoney;

				if (AMMoney <= 0)
					cout << "0���� ���� �� �����ϴ�. �ٽ� �Է����ּ���. : ";
				else
					break;
			}
			am.Withdraw(AMMoney);
			if (Money - AMMoney > 0)
				bb.Withdraw(Money - AMMoney);
			cout << "�������� ����Ͽ� " << Money - AMMoney << "���� �����Ǿ����ϴ�." << endl;
			break;
		}
		else if (cur == 'n')
		{
			bb.Withdraw(Money);
			am.Deposit(Money * 0.05);
			break;
		}
		else
			cout << "�ٽ� �Է����ּ���!" << endl;
	}
	bb.PrintMoney();
	cout << ", ";
	am.PrintMoney();
	cout << endl;
}