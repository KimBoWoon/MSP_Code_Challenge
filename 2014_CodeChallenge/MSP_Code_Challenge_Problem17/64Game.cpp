/*
���� MadPlay�� �ڵ��� �ҽ� �ڵ��Դϴ�.
http://blog.naver.com/madplay �� �湮�ϼż�
�ڵ� ��� ���θ� �ݵ�� �����ֽñ� �ٶ��ϴ�.

Copyright (C) MadPlay's SW Life.
*/



#include <iostream>
#include <string>
#include <iomanip> // setw�� ���� ��� ����
#include <vector>
//#include <conio.h>
//#include <Windows.h> // Clear Screen, exit ���� ���� ��� ����
#include <time.h>
using namespace std;
#pragma warning(disable:4996) // ���־� ��Ʃ��� secure ���� ����



const int MAXROW = 4;
const int MAXCOL = 4;



class Game {
private:
	int bestScore; // �ְ� ���� ��� ����
	int score; // ���� ���� ��� ����
	vector<int> scoreList; // ���� ���� ����
	int number[MAXROW][MAXCOL]; // 4x4 �����ǿ� ���� ���
public:
	// ���� �ʱ�ȭ
	void gameInit() {
		bestScore = calcBestScore();
		score = 0;
		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				number[row][col] = 0;
			}
		}
		addRandomValue(); // �ʱ� ���� ����
	}



	// ���� ����
	void addRandomValue() {
		int loopCount = 0;

		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				if (number[row][col] == 0)
					loopCount = 1;
			}
		}

		while (loopCount) {
			int ranRow = rand() % 4;
			int ranCol = rand() % 4;

			if (number[ranRow][ranCol] == 0) {
				number[ranRow][ranCol] = 2;
				break;
			}
		}
	}



	// �ְ� ������ ����Ѵ�.
	int calcBestScore() {
		int max = 0;
		int length = scoreList.size();
		for (int idx = 0; idx < length; idx++) {
			if (max < scoreList[idx]) max = scoreList[idx];
		}
		return max;
	}



	// ���� ���
	void showPoint() {
		cout << "BEST : " << bestScore << endl;
		cout << "SCORE : " << score << endl;
	}



	// �ȳ��޽��� ���
	void showKeyMessage() {
		cout << "W : ��� ���� ����" << endl;
		cout << "A : ��� ���� ��������" << endl;
		cout << "S : ��� ���� �Ʒ���" << endl;
		cout << "D : ��� ���� ����������" << endl;
		cout << "X : ��������" << endl;
	}



	// ������ ���
	void showMainGround() {
		int row = 0;
		for (int width = 0; width < 4; width++) {
			for (int height = 0; height < 41; height++) {
				if (height % 10 == 0) cout << "+";
				else cout << "-";
			}


			// ������ ����.... �ϱ�...-_-
			cout << endl;
			cout << "| " << setw(10) << " | " << setw(10) << " | " << setw(10)
				<< " | " << setw(10) << " | " << endl;
			cout << "| " << setw(4) << number[row][0] << setw(6) << " | " << setw(4)
				<< number[row][1] << setw(6) << " | " << setw(4) << number[row][2] << setw(6)
				<< " | " << setw(4) << number[row][3] << setw(6) << " | " << endl;
			cout << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " | "
				<< setw(10) << " | " << endl;
			row++;
		}
		for (int col = 0; col < 41; col++) {
			if (col % 10 == 0) cout << "+";
			else cout << "-";
		}
		cout << endl;
	}



	void playGame() {
		gameInit();
		while (true) {
			system("cls");
			showMainGround();
			showPoint();
			showKeyMessage();


			char keyInput = 'x';
			//keyInput = getch(); // Ű �Է�
			cin >> keyInput;
			allBlocksMove(keyInput); // Ű �Է¿� ���� ��� �̵�
			switch (keyInput) {
			case 'w': case 'a': case 's': case 'd':
				calcBlocksAddCondition(keyInput); // ���� �� �ִ� ����� �ִ� �� �˻�
				allBlocksMove(keyInput); // �˻� �� ��� �ݿ�, ��� �̵�
				if (isWin()) showEndMessage(1); // �¸� ���� �˻�
				if (isEnd()) showEndMessage(0); // �й� ���� �˻�
				break;


			case 'x': return;
			default: break;
			}
		}
	}



	// ���� �� �ִ� �� ����ϱ�!
	void calcBlocksAddCondition(char input) {
		switch (input) {
		case 'w': case 'W':
			for (int row = 0; row < MAXROW - 1; row++) {
				for (int col = 0; col < MAXCOL; col++) {
					if (number[row][col] == number[row + 1][col]) {
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // ��������
						number[row + 1][col] = 0;
					}
				}
			}
			break;



		case 'a': case 'A':
			for (int col = 0; col < MAXCOL - 1; col++) {
				for (int row = 0; row < MAXROW; row++) {
					if (number[row][col] == number[row][col + 1]){
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // ��������
						number[row][col + 1] = 0;
					}
				}
			}
			break;

		case 's': case 'S':
			for (int row = MAXROW - 1; row > 0; row--) {
				for (int col = MAXCOL - 1; col >= 0; col--) {
					if (number[row][col] == number[row - 1][col]) {
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // ��������
						number[row - 1][col] = 0;
					}
				}
			}
			break;



		case 'd': case 'D':
			for (int col = MAXCOL - 1; col > 0; col--) {
				for (int row = MAXROW - 1; row >= 0; row--) {
					if (number[row][col] == number[row][col - 1]) {
						number[row][col] = number[row][col] * 2;
						score = score + number[row][col]; // ��������
						number[row][col - 1] = 0;
					}
				}
			}
			break;
		}
	}



	// ��� �̵� ��Ű��
	// �ݺ� �̵���Ű�� �κ��� �����Ͽ����ϴ�.
	void allBlocksMove(char input) {
		switch (input)
		{
		case 'w': case 'W':
			for (int loop = 0; loop < 10; loop++)
				for (int row = 0; row < MAXROW - 1; row++) {
					for (int col = 0; col < 4; col++) {
						if (number[row][col] == 0) {
							number[row][col] = number[row + 1][col];
							number[row + 1][col] = 0;
						}
					}
				}
			break;



		case 'a': case 'A':
			for (int loop = 0; loop < 10; loop++)
				for (int col = 0; col < MAXCOL - 1; col++) {
					for (int row = 0; row < MAXROW; row++) {
						if (number[row][col] == 0) {
							number[row][col] = number[row][col + 1];
							number[row][col + 1] = 0;
						}
					}
				}
			break;



		case 's': case 'S':
			for (int loop = 0; loop < 10; loop++)
				for (int row = MAXROW - 1; row > 0; row--) {
					for (int col = MAXCOL - 1; col >= 0; col--) {
						if (number[row][col] == 0) {
							number[row][col] = number[row - 1][col];
							number[row - 1][col] = 0;
						}
					}
				}
			break;



		case 'd': case 'D':
			for (int loop = 0; loop < 10; loop++)
				for (int col = MAXCOL - 1; col > 0; col--) {
					for (int row = MAXROW - 1; row >= 0; row--) {
						if (number[row][col] == 0) {
							number[row][col] = number[row][col - 1];
							number[row][col - 1] = 0;
						}
					}
				}
			break;
		}
		addRandomValue();
	}



	// �¸� ���� Ȯ��
	bool isWin() {
		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				if (number[row][col] == 2048) return true;
			}
		}
		return false;
	}



	// �й� ���� Ȯ��
	bool isEnd() {
		for (int row = 0; row < MAXROW - 1; row++) {
			for (int col = 0; col <= MAXCOL - 1; col++) {
				if (number[row][col] == number[row][col + 1]) return false;
				// ���� ���� ���ڰ� ������ �й����� ����
			}
		}



		for (int col = 0; col < MAXCOL - 1; col++) {
			for (int row = 0; row <= MAXROW - 1; row++) {
				if (number[row][col] == number[row + 1][col]) return false;
				// ���Ʒ� ���� ���ڰ� ������ �й����� ����
			}
		}



		for (int row = 0; row < MAXROW; row++) {
			for (int col = 0; col < MAXCOL; col++) {
				if (number[row][col] == 0) return false;
				// �ϳ��� ��� ������ �й����� ����
			}
		}
		return true;
	}



	// ��� ���� �� �ȳ� �޽��� ��� �� ó��
	void showEndMessage(int type) {
		system("cls");
		char choice;


		if (type) {
			scoreList.push_back(score);
			cout << "�¸��Ͽ����ϴ�. ������ �� �� �� �Ͻðڽ��ϱ�? (y/n) : ";
		}
		else cout << "�й��Ͽ����ϴ�. ������ �� �� �� �Ͻðڽ��ϱ�? (y/n) : ";


		fflush(stdin);
		//choice = getch();
		cin >> choice;
		if (choice == 'y') playGame();
		else if (choice == 'n') exit(0);
		else showEndMessage(type);
	}
};

int main(void)
{
	srand((unsigned)time(NULL));
	Game game;
	game.playGame();
}