#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    for (int i = 0; i < floor; i++) {
        for (int j = floor - 1 - i ; j > 0; j--) {
            cout << "S";
        }
        for (int k = i * 2 + 1; k > 0 ; k--) {
            cout << "*";
        }
        cout << endl;
    }   
    return 0;
}