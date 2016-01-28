#include "Singing_Room.h"

int main()
{
	ifstream input;
	int num;
	vector<Song> v;

	input.open("�뷡��.txt");
	if (input.fail())
	{
		cerr << "���� ����" << endl;
		exit(1);
	}
	while (!(input.eof()))
	{
		Song s;
		s.SetSong(input);
		v.push_back(s);
	}

	cout << "��ȣ ���� - ����" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i<v.size(); i++)
		v[i].Print();

	while (true)
	{
		try
		{
			cout << endl << "�뷡 ��ȣ�� �Է����ּ���" << endl;
			cout << "0�� �Է��ϸ� ���α׷��� ����˴ϴ�. : ";
			cin >> num;
			cout << endl;
			if (num > v.size())
				throw "�Է¹����� �ʰ��߽��ϴ�.";
			if (num == 0)
				return 0;
			v[num - 1].PrintLyrics();
		}
		catch (const char *s)
		{
			cout << s << endl;
		}
	}

	input.close();

	return 0;
}