#include <iostream>
#include <string>

using namespace std;

class User {
public:
    virtual ~User() = default;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual int GetHP() const = 0;
    virtual void DoAttack() = 0;

    virtual void IncreaseItem() = 0;
    virtual int GetItem() const = 0;

    virtual void Print(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const User& user) {
        user.Print(os);  // PrintInfo 호출
        return os;
    }
};


class Warrior : public User {
private:
    int hp;
    int itemCnt;

public:
    Warrior() : hp(20), itemCnt(0) {}


    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    int GetHP() const override; // const 키워드 추가
    void DoAttack() override;

    void IncreaseItem() override { itemCnt++; }
    int GetItem() const override { return itemCnt; }

    void Print(ostream& os) const override {
        os << "(Warrior HP: " << GetHP() << ", 아이템: " << GetItem() << "개)" << endl;
    }
};

class Magician : public User {
private:
    int hp;
    int itemCnt;

public:
    Magician() : hp(20), itemCnt(0) {}

    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    int GetHP() const override;
    void DoAttack() override;

    void IncreaseItem() override { itemCnt++; }
    int GetItem() const override { return itemCnt; }

    // PrintInfo 메서드 구현
    void Print(ostream& os) const override {
        os << "(Magician HP: " << GetHP() << ", 아이템: " << GetItem() << "개)" << endl;
    }
};
