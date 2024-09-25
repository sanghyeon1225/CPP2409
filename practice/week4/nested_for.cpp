#include <iostream>
using namespace std;

int main()
{
    cout << "구구단 출력:" << endl;

    //2단부터 9단까지 반복
    for (int i = 2; i <= 9; ++i){
        cout << i << "단:" << endl;

        //각 단의 곱셈 표 출력
        for (int j = 1; j <= 9; ++j) {
            cout << i << " x " << j << " = " << (i * j) << endl;
        }
        cout << endl; // 각 단의 출력을 구분하기 위해 개행 추가
    }

    return 0;
}