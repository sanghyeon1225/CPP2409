#include <iostream>
using namespace std;


class RemoteControl {
public:
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television: public RemoteControl {
public:
    void TurnON() {
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() {
        cout << "TV를 끕니다." << endl;
    }
};

class Refrigerator: public RemoteControl {
public:
    void TurnON() {
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() {
        cout << "냉장고를 끕니다." << endl;
    }
};


int main() {
    // TV를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteTV = new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();

    // 냉장고를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();
    remoteRefrigerator->TurnOFF();

    delete remoteTV, remoteRefrigerator;
}