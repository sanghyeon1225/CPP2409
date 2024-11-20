#include <iostream>
#include <string>

using namespace std;

class User{
public:
    int hp;
    int itemCnt;
    int xpos;
    int ypos;

    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();
    void DoAttack();

    friend ostream& operator<<(ostream& os, const User& user) { // 멤버함수 불가능
        os << "(현재 HP는 " << user.hp << "이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다.)" << endl;
        return os;
    }
};

class Warrior : public User {
public:
    Warrior() : User() {}
    void DoAttack();

    friend ostream& operator<<(ostream& os, const Warrior& user) { // 멤버함수 불가능
        os << "(현재 HP는 " << user.hp << "이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다.)" << endl;
        return os;
    }
};

class Magician : public User {
public:
    Magician() : User() {}
    void DoAttack();

    friend ostream& operator<<(ostream& os, const Magician& user) { // 멤버함수 불가능
        os << "(현재 HP는 " << user.hp << "이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다.)" << endl;
        return os;
    }
};
