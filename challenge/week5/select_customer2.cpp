#include <iostream>
#include <string>
using namespace std;
int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i+1 <<"의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 <<"의 나이: ";
        cin >> ages[i];
    }

    int check;
    bool exit_flag = true;

    int max = ages[0];
    int max_num = 0;
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] > max){
            max = ages[i];
            max_num = i;
        }
    }

    int min = ages[0];
    int min_num = 0;
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] < min) {
            min = ages[i];
            min_num = i;
        }
    }
    while(exit_flag) {
        cout << "1. 가장 나이가 많은 사람 출력" << endl;
        cout << "2. 가장 나이가 적은 사람 출력" << endl;
        cout << "3. 종료" << endl;
        cin >> check;
        switch (check) {
            case 1: {
                cout << "가장 나이가 많은 사람 : " << names[max_num] << "(" << ages[max_num] << "세) " << endl; 
                break;
            }
            case 2: {
                cout << "가장 나이가 적은 사람 : " << names[min_num] << "(" << ages[min_num] << "세) " << endl;
                break;
            }
            case 3: {
                exit_flag = false;
                break;
            }
            default: {
                for (int i = 0; i < maxPeople; i++) {
                    cout << names[i] << "(" << ages[i] << "세)" << endl;
                }
                exit_flag = false;
                break;
            }
        }
    }
    return 0;
}