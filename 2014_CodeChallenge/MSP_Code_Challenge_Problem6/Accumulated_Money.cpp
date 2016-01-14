#include "Accumulated_Money.h"

AccumulatedMoney::AccumulatedMoney()
{
	input.open("������.txt");

	if (input.fail())
	{
		cerr << "������ ã�� �� �����ϴ�!";
		exit(1);
	}

	input >> Money;
	input.close();
}
AccumulatedMoney::~AccumulatedMoney()
{
	output.open("������.txt");
	output << Money;
	output.close();
}
int AccumulatedMoney::GetMoney()	{ return Money; }
void AccumulatedMoney::Deposit(double Money)
{
	if (Money > 0)
	{
		this->Money += Money;
		cout << Money << "���� �����Ǿ����ϴ�." << endl << endl;
	}
	else
		cout << "0���� ���� �� �����ϴ�." << endl;
}
void AccumulatedMoney::Withdraw(double Money)
{
	if (Money > 0 && this->Money >= Money)
		this->Money -= Money;
	else
		cout << "���� ������ �ִ� �ܾ׺��� Ŭ �� �����ϴ�!" << endl;
}
void AccumulatedMoney::PrintMoney() const	{ cout << "������ : " << Money; }