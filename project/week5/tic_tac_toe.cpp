#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x,y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수 선언

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; //현재 유저의 돌을 저장하기 위한 문자 변수
    while (true) {
        // 1. 누구 차례인지 출력
        switch (k % 2) {
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }
        
        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        // x와 y 좌표를 반대로 생각하기 위해서 board[y][x]에 값 할당
        if (board[y][x] != ' ') {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        // x와 y 좌표를 반대로 생각하기 위해서 board[y][x]에 값 할당
        board[y][x] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j == numCell -1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 빙고 시 승자 출력 후 종료
        // 6-1 가로 빙고 확인 
        for (int i = 0; i < numCell; i++) {
            int count = 0;
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == currentUser) {
                    count++;
                }
            }
            if (count == 3) {
                cout << currentUser << "의 가로 빙고 달성!" << endl;
                return 0;
            }
        }
        // 6-2 세로 빙고 확인
         for (int j = 0; j < numCell; j++) {
            int count = 0;
            for (int i = 0; i < numCell; i++) {
                if (board[i][j] == currentUser) {
                    count++;
                }
            }
            if (count == 3) {
                cout << currentUser << "의 세로 빙고 달성!" << endl;
                return 0;
            }
        }
        // 6-3 대각선 빙고 확인
        if(board[0][0] == currentUser && board[1][1] == currentUser & board[2][2] == currentUser) {
            cout << currentUser << "의 대각선 빙고 달성!" << endl;
            break;
        }
        else if (board[2][0] == currentUser && board[1][1] == currentUser & board[0][2] == currentUser) {
            cout << currentUser << "의  대각선 빙고 달성!" << endl;
            break;
        }

        // 7. 모든 칸이 찼으면 종료
        if (k == 8) {
            cout << "모든 칸이 찼으므로 무승부 처리" << endl;
            break;
        }
        k++;
    }
    return 0;
}