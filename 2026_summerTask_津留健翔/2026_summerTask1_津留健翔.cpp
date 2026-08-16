#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // 変数の初期化
    int answer = -1;      // プレイヤーの入力した予想数字、初期値は範囲外の-1
    int question;         // 生成する正解の数字
    int count = 0;        // カウントする変数

    // 乱数の初期化
    srand((unsigned int)time(nullptr));

    // 0～100の範囲でランダムな正解の数字を生成
    question = rand() % 101;

    // ゲーム開始のメッセージを表示
    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;

    // 正解（question）と入力値（answer）が一致するまで繰り返す
    while (question != answer)
    {
        count++; // 試行回数を1増やす

        // 0～100 が入力されるまでループ
        while (true)
        {
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer; // プレイヤーの数字入力

            // 入力チェック
            if (answer < 0 || answer > 100)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                // 正しい範囲の数字が入力されたら入力ループを抜ける
                break;
            }
        }

        // 入力された数字と正解を比較してヒントを表示
        if (question > answer)
        {
            cout << "もっと大きい数字です。" << endl;
        }
        else if (question < answer)
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }

    // 終了処理と結果表示
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    return 0; // プログラム終了
}