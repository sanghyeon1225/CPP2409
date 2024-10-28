#include <iostream>
using namespace std;

template<int N>
// isValid 함수 매개변수를 선언할 때, board의 크기를 numCell로 넣어주면 동적 할당이라 에러가 발생하여 template 함수를 사용했습니다.
bool isValid(int x, int y, int numCell, char (&board)[N][N]) {
	if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
		cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
		return false;
	}
	if (board[y][x] != ' ') {// 좌표범위의 입력값이 중복될때
		cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
		return false;
	}
	return true;
}

template<int N>
// 승자를 체크하는 checkWin 함수, 내부에서 가로와 세로, 대각선의 경우에 따른 승자를 판단함
bool checkWin(char currentUser, int numCell, char (&board)[N][N]) {
	// 6.1. 가로/세로 돌 체크하기
	for (int i = 0; i < numCell; i++) {
		// 한 줄에 놓인 같은 유저의 돌 개수를 뜻하는 row_count, column_cout 선언
		int row_count = 0;
		int column_count = 0;
		// for문을 돌면서 같은 가로 줄에 currentUser와 같은 돌이 있다면 row_count 1 추가
		// 세로 줄에 같은 돌이 있다면 column_count 1 추가
		for (int j = 0; j < numCell; j++) {
			if (board[i][j] == currentUser) {
				row_count++;
			}
			if (board[j][i] == currentUser) {
				column_count++;
			}
		}
		// row_count나 column_count가 numCell과 같다면 빙고임을 출력하고 true를 리턴
		if (row_count == numCell) {
			cout << "가로에 모두 돌이 놓였습니다!!" << endl;
			return true;
		}
		if (column_count == numCell) {
			cout << "세로에 모두 돌이 놓였습니다!!" << endl;
			return true;
		}
	}

	// 6.2. 대각선을 체크하기
	// TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
	// HINT: for 문
	// 대각선에 놓여있는 currentUser와 같은 돌의 개수를 뜻하는 diag_plus와 diag_minus 선언 (plus는 우상향 대각선을 뜻하고, minus 우하향 대각선을 뜻함)
	int diag_plus = 0;
	int diag_minus = 0;
	for (int i = 0; i < numCell; i++) {
		// 좌상단에서 우하단 방향으로 돌의 개수 체크 
		if (board[i][i] == currentUser) {
			diag_minus++;
		}
		// 우상단에서 좌하단 방향으로 돌의 개수 체크
		if (board[i][numCell - i - 1] == currentUser) {
			diag_plus++;
		}
	}
	if (diag_minus == numCell) {
		cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
		return true;
	}
	if (diag_plus == numCell) {
		cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
		return true;
	}
	return false;
}

int main() {
	// 게임을 진행하는 데 필요한 변수 선언

	const int numCell = 3; // 보드판의 가로 세로 길이
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		// isValid 함수를 호출하여 return이 true일 경우 정상 실행, false일 경우 if문에 걸려서 continue; 실행
		if (!isValid(x, y, numCell, board)) {
			continue;
		}

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[y][x] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
			for (int k = 0; k < numCell - 1; k++){
				cout << "---|";
			}
			cout << "---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		for (int k = 0; k < numCell - 1; k++){
			cout << "---|";
		}
		cout << "---" << endl;

		bool isWin = false; // 승리 여부 저장할 변수

		// checkWin 함수를 통해 승리 여부 확인
		isWin = checkWin(currentUser, numCell, board);

		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}