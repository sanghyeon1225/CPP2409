#include <iostream>
#include <string>

using namespace std;

class User {
public:
    virtual ~User() = default; // 가상 소멸자
    virtual void IncreaseHP(int inc_hp) = 0; // 순수 가상 함수
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual int GetHP() const = 0;
    virtual void DoAttack() = 0;

    virtual void IncrementItemCount() = 0; // 아이템 개수 증가 함수
    virtual int GetItemCount() const = 0; // 아이템 개수 조회 함수

    // friend 연산자 오버로딩 함수 선언
    friend ostream& operator<<(ostream& os, const User& user) {
        os << "User 상태 출력 기능은 파생 클래스에서 구현해야 합니다." << endl;
        return os;
    }
};


class Warrior : public User {
private:
    int hp;
    int itemCnt;

public:
    Warrior() : hp(20), itemCnt(0) {}

    void IncreaseHP(int inc_hp) {};
    void DecreaseHP(int dec_hp) {};
    int GetHP() const override {};

    void DoAttack() override {};

    void IncrementItemCount() override { itemCnt++; }
    int GetItemCount() const override { return itemCnt; }

    friend ostream& operator<<(ostream& os, const Warrior& warrior) {
        os << "(Warrior HP: " << warrior.hp << ", 아이템: " << warrior.itemCnt << "개)" << endl;
        return os;
    }
};

class Magician : public User {
private:
    int hp;
    int itemCnt;

public:
    Magician() : hp(20), itemCnt(0) {}

    void IncreaseHP(int inc_hp) {};
    void DecreaseHP(int dec_hp) {};
    int GetHP() const override {};

    void DoAttack() override {};
    void IncrementItemCount() override { itemCnt++; }
    int GetItemCount() const override { return itemCnt; }
    
    friend ostream& operator<<(ostream& os, const Magician& magician) {
        os << "(Magician HP: " << magician.hp << ", 아이템: " << magician.itemCnt << "개)" << endl;
        return os;
    }
};
