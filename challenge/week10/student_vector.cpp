#include <iostream>
#include <vector> 
#include <string> 
using namespace std;

int main() {
    vector<int> score;
    int input;
    while(true) {
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> input;
        if (input == -1)
            break;
        score.push_back(input);
    }

    int sum;
    for (auto elem : score) {
        sum += elem;
    }

    cout << "성적 평균=" << sum / score.size() << endl;
    return 0;
}