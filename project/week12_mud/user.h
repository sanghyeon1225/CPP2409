#include <iostream>
#include <string>

using namespace std;

class User{
private:
    int hp;
public:
    int itemCnt;
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();

    friend ostream& operator<<(ostream& os, const User& user) { // 멤버함수 불가능
        os << "(현재 HP는 " << user.hp << "이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다.)" << endl;
        return os;
    }
};