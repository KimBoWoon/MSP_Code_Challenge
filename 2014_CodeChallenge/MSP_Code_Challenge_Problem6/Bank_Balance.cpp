#include "Accumulated_Money.h"

BankBalance::BankBalance()
{
	input.open("�����ܰ�.txt");

	if (input.fail())
	{
		cerr << "������ ã�� �� �����ϴ�!";
		exit(1);
	}

	input >> Money;
	input.close();
}
BankBalance::~BankBalance()
{
	output.open("�����ܰ�.txt");
	output << Money;
	output.close();
}
int BankBalance::GetMoney()	{ return Money; }
void BankBalance::Deposit(int Money)
{
	if (Money > 0)
		this->Money += Money;
	else
		cout << "0���� ���� �� �����ϴ�." << endl;
}
void BankBalance::Withdraw(int Money)
{
	if (Money > 0 && this->Money >= Money)
		this->Money -= Money;
	else
		cout << "���� ������ �ִ� �ܾ׺��� Ŭ �� �����ϴ�!" << endl;
}
void BankBalance::PrintMoney() const	{ cout << "���� ���� �ܰ� : " << Money; }