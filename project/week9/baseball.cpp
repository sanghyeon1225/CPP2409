#include <iostream>
#include <string>
#include <time.h>

using namespace std;

bool checkNumber(int newNum){
	bool same = false;
	// 숫자가 0으로 시작해도 첫 번째 자리에 0을 넣어줄 수 있음.
	int firstNum = newNum / 100;
	int secondNum = (newNum / 10) % 10;
	int thirdNum = newNum % 10;
	
	
	if (thirdNum != secondNum && secondNum != firstNum && firstNum != thirdNum){
		same = true;
	}

	return same;
}

// stirke와 ball이 0이면 아웃으로 출력, strike가 3개라면 정답이라 출력하며 main에서 프로그램 종료, 그 외에는 몇개의 strike와 ball인지 출력
void sayHint(int strike, int ball, int userNumber) {
	if (strike == 0 && ball == 0) {
		cout << userNumber << "의 결과 : " << "아웃 입니다." << endl;
	} // strike가 3일 때 정답을 맞췄으므로 게임을 종료함
	else if (strike == 3) {
		cout << "정답을 맞췄습니다. 축하합니다.";
	} // 아웃과 정답의 경우가 아니라면 strike와 ball의 개수를 알려줌
	else {
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
	}
}

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수
	
	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
		
		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		same = checkNumber(randomNum);

		firstNum = randomNum / 100;
		secondNum = (randomNum / 10) % 10;
		thirdNum = randomNum % 10;
		
		if (same == true) {
			break;
		}
	}
	
	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성

			// int로 userNumber를 받아오고 있는데 만약 사용자가 012를 입력하면 userNumber에는 12가 저장이 됨. 따라서 정상 실행 가능
			// 입력에 7을 입력하면 userNumber에는 7이 저장되는데, 이는 첫번째 수와 두번째 수 모두 0이므로 중복된 숫자를 받았다고 판별
			if (userNumber / 100 == 0) {
				same = checkNumber(userNumber);
			}
			else if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}
			
			same = checkNumber(userNumber);

			guessFirst = userNumber / 100;
			guessSecond = (userNumber / 10)% 10;
			guessThird = userNumber % 10;
			
			
			if(same == false) {
				cout << "입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요" << endl;
				continue;
			}
			if (same == true) {
				break;
			}
		}
		// 정답 숫자를 저장하는 배열 ranNum
		int ranNum[3] = {firstNum, secondNum, thirdNum};
		// 사용자가 정한 숫자를 저장하는 배열 userNum
		int userNum[3] = {guessFirst, guessSecond, guessThird};

		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성

		// strike, ball을 세기 위한 코드블록
		// 각각 3번씩 반복하는 2중 for문을 만들어서 ranNum[]의 첫번째 원소부터 userNum[]의 모든 원소를 비교함.
		// 이때 같은 값이 존재하고, i와 j가 다르다면 ball을 추가함. (i와 j가 같으면 strike의 경우)
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++){
				if (ranNum[i] == userNum[j]) {
					if (i == j)
						strike++;
					else
						ball++;
				}
			}
		}
		// 방금 카운팅한 strike와 ball의 수를 토대로 사용자에게 힌트를 주는 함수 구현 
		sayHint(strike, ball, userNumber);

		if (strike == 3) {
			break;
		}

		turn += 1;
	}

	return 0;
}