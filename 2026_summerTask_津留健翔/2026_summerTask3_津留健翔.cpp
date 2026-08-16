#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	const int MASU = 9;
	const int DICE_MAX = 6;

	int i;
	int masu[MASU]; // 0:誰も取っていない  1:プレイヤーが取った  2:CPUが取った
	int dice1, dice2, sum;
	int choice;
	int candidate[3];
	bool candidateOK[3];
	int okCount;
	int takenCount = 0;
	bool canTake;

	bool trunFlag = true;       // true:プレイヤーのターン  false:CPUのターン
	bool judgementFlag = false; // true:プレイヤーの勝ち

	srand((unsigned int)time(NULL));

	for (i = 0; i < MASU; i++)
	{
		masu[i] = 0;
	}

	cout << "===================   Jackpot   ============================" << "\n";
	cout << "1から9までのマスを、プレイヤーとCPUが交互にサイコロを振って陣取りするゲームです" << "\n";
	cout << "六面サイコロを2個振り、出た目、または出た目の合計のマスを取ることができます" << "\n";
	cout << "===================   GAME STRAT   ============================" << "\n";

	while (true)
	{
		cout << "-----------------------------------------" << "\n";
		cout << "現在の盤面" << "\n";
		for (i = 0; i < MASU; i++)
		{
			cout << i + 1 << ":";
			if (masu[i] == 0)
			{
				cout << "空き ";
			}
			else if (masu[i] == 1)
			{
				cout << "あなた ";
			}
			else
			{
				cout << "CPU ";
			}
		}
		cout << "\n";

		dice1 = rand() % DICE_MAX + 1;
		dice2 = rand() % DICE_MAX + 1;
		sum = dice1 + dice2;

		candidate[0] = dice1;
		candidate[1] = dice2;
		candidate[2] = sum;

		okCount = 0;
		for (i = 0; i < 3; i++)
		{
			if (candidate[i] <= MASU && masu[candidate[i] - 1] == 0)
			{
				candidateOK[i] = true;
				okCount++;
			}
			else
			{
				candidateOK[i] = false;
			}
		}

		if (trunFlag)
		{
			cout << "PLAYER TRUN" << "\n";
			cout << "サイコロの目は " << dice1 << " と " << dice2 << " (合計 " << sum << ") です" << "\n";

			if (okCount == 0)
			{
				cout << "取れるマスがありません。あなたの負けです。" << "\n";
				judgementFlag = false;
				break;
			}

			cout << "取れるマス：";
			for (i = 0; i < 3; i++)
			{
				if (candidateOK[i])
				{
					cout << candidate[i] << " ";
				}
			}
			cout << "\n";

			while (true)
			{
				cout << "取るマスの番号を入力してください" << "\n";
				cin >> choice;

				canTake = false;
				for (i = 0; i < 3; i++)
				{
					if (candidateOK[i] && candidate[i] == choice)
					{
						canTake = true;
					}
				}

				if (canTake)
				{
					break;
				}
				else
				{
					cout << "入力に誤りがあります。再度入力してください。" << "\n";
				}
			}

			masu[choice - 1] = 1;
			takenCount++;
			cout << choice << "のマスを取りました" << "\n";

			if (takenCount == MASU)
			{
				cout << "全てのマスが埋まりました。" << "\n";
				judgementFlag = true;
				break;
			}

			trunFlag = false;
		}
		else
		{
			cout << "ENEMY TRUN" << "\n";
			cout << "サイコロの目は " << dice1 << " と " << dice2 << " (合計 " << sum << ") です" << "\n";

			if (okCount == 0)
			{
				cout << "CPUは取れるマスがありません。あなたの勝ちです。" << "\n";
				judgementFlag = true;
				break;
			}

			while (true)
			{
				i = rand() % 3;
				if (candidateOK[i])
				{
					choice = candidate[i];
					break;
				}
			}

			masu[choice - 1] = 2;
			takenCount++;
			cout << "CPUは" << choice << "のマスを取りました" << "\n";

			if (takenCount == MASU)
			{
				cout << "全てのマスが埋まりました。" << "\n";
				judgementFlag = false;
				break;
			}

			trunFlag = true;
		}
	}

	cout << "===================   RESULT   ============================" << "\n";
	if (judgementFlag)
	{
		cout << "PLAYER WINNER" << "\n";
	}
	else
	{
		cout << "ENEMY WINNER" << "\n";
	}

	return 0;
}