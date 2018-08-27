// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 수정 일자(AI ver.): 2018-06-05
// 학번 : 20171676
// 이름 : 이정우
#include "GameManager.h"

using namespace std;

int main(){
    int numOfGames, delay;
    int turn = 0;
    cout << "Num of Games: ";
    cin >> numOfGames;
    cout << "Set Delay(ms): ";
    cin >> delay;
    for(int i = 0; i < numOfGames; i++){
        GameManager game;
        int currentTurn = game.play(i+1, delay);
        cout << "Game " << i+1 << ": " << currentTurn << endl;
        turn += currentTurn;
    }
    cout << "Total Games: " << numOfGames << endl;
    cout << "Average of Turns: " << turn / numOfGames << endl;
    return 0;
}
