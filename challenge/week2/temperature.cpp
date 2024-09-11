#include <iostream>
#include <string>
using namespace std;

int main()
{
   float F_tem;

    cout << "화씨온도:";
    cin >> F_tem;
    cout << "섭씨온도 = " << (5.0 / 9.0) * (F_tem - 32);
    return 0;
}