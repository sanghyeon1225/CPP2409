#include <iostream>
using namespace std;

int main()
{
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    largest = a; // 우선 a를 가장 큰 수라고 가정하여 largest에 할당
    
    if (b > largest) { // b가 largest보다 크면 b를 largest에 할당
        largest = b;
    }
    if (c > largest) { // c가 largest보다 크면 c를 largest에 할당
        largest = c;
    }

    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}