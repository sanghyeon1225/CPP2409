#include <iostream>
#include <string>
#include "user.h"
#include <vector>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, int user_x, int user_y, User* user);
bool userMove(vector<vector<int>>& map, string user_input, int& user_x, int& user_y, User &user);
bool CheckUser(User &user);

User *user;

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>>map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
	
	string select;
	cout << "플레이를 원하는 직업을 입력하세요 (Magician = M, Warrior = W)" << endl;
	cin >> select;

	if (select == "M") {
		user = new Magician();
	} else if(select == "W") {
		user = new Warrior();
	} else {
		cout << "W나 M만 입력하세요." << endl;
		return 0;
	}

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프    
		
		
		// 사용자의 입력을 저장할 변수
		string user_input = "";
		if (!CheckUser(*user)) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		
		// 현재 체력 출력
		cout << "현재 HP: " << user->GetHP() << " ";

		// 사용자 입력 받기
		cout << "명령어를 입력하세요 (up,down,left,right,map,info,attack,quit): ";
		cin >> user_input;

		// 사용자 입력이 quit이면 게임 종료
		if (user_input == "quit") {
			cout << "종료합니다.";
			break;
		}

		// 사용자 입력에 따라 유저 좌표 이동
		bool input_check = userMove(map, user_input, user_x, user_y, *user);
		
		// 사용자 입력이 up down left right map이 아니라면 다시 입력 받기
		if (input_check == false) {
			continue;
		}
		
		// 유저의 위치에 존재하는 아이템, 적, 포션에 따른 상태를 체크하여 hp 변화
		checkState(map, user_x, user_y, user);

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " User |"; // 직업에 따라 Warrior 또는 Magician 출력
            }
            else {
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    cout << "      |"; // 6칸 공백
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |"; // 양 옆 2칸 공백
                    break;
                case 3:
                    cout << " 포션 |"; // 양 옆 1칸 공백
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}


// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 유저의 위치에 있는 아이템, 적, 포션에 따른 상태를 변화하는 함수
void checkState(vector<vector<int>>& map, int user_x, int user_y, User* user) {
	if(map[user_y][user_x] == 1) {
		cout << "아이템이 있습니다." << endl;
		user->IncrementItemCount();
	}
	else if(map[user_y][user_x] == 2) {
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		user->DecreaseHP(2);
	}
	else if(map[user_y][user_x] == 3) {
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
		user->IncreaseHP(2);
	}
}

// 유저의 입력에 따른 위치를 이동시키는 함수
bool userMove(vector<vector<int>>& map, string user_input, int& user_x, int& user_y, User &user) {
	if(user_input == "up") {
		// 입력받은 값에 따라 좌표를 옮기고, hp 1 감소
		user_y -= 1;
		user.DecreaseHP(1);
		bool inMap = checkXY(user_x, mapX, user_y, mapY);
		
		// 유효한 이동이 아니라면 원래 좌표로 복귀
		if (inMap == false) {
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			user_y += 1;
			user.IncreaseHP(1);
		}
		// 유효한 이동이라면 이동 성공했다는 문구 출력과 현재 map 상태 출력
		else {
			cout << "위로 한 칸 올라갑니다." << endl;
			displayMap(map, user_x, user_y);
		}
	}
	else if(user_input == "down") {
		user_y += 1;
		user.DecreaseHP(1);
		bool inMap = checkXY(user_x, mapX, user_y, mapY);

		if (inMap == false) {
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			user_y -= 1;
			user.IncreaseHP(1);
		}
		else {
			cout << "위로 한 칸 내려갑니다." << endl;
			displayMap(map, user_x, user_y);
		}
	}
	else if(user_input == "left") {
		user_x -= 1;
		user.DecreaseHP(1);
		bool inMap = checkXY(user_x, mapX, user_y, mapY);

		if (inMap == false) {
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			user_x += 1;
			user.IncreaseHP(1);
		}
		else {
			cout << "왼쪽으로 이동합니다." << endl;
			displayMap(map, user_x, user_y);
		}
	}
	else if(user_input == "right") {
		user_x += 1;
		user.DecreaseHP(1);
		bool inMap = checkXY(user_x, mapX, user_y, mapY);
		if (inMap == false) {
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			user_x -= 1;
			user.IncreaseHP(1);
		}
		else {
			cout << "오른쪽으로 이동합니다." << endl;
			displayMap(map, user_x, user_y);
		}
	}
	else if (user_input == "map") {
		// TODO: 지도 보여주기 함수 호출
		displayMap(map, user_x, user_y);
	}
	else if (user_input == "info") {
		cout << user << endl;
	}
	else if (user_input == "attack") {
		user.DoAttack();
	}
	else {
		cout << "잘못된 입력입니다." << endl;
		return false;
	}
	return true;
}

bool CheckUser(User &user) {
    if (user.GetHP() <= 0)
        return false;
    else
        return true;
}
