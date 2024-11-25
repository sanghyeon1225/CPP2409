#include "user.h"

// Warrior 클래스의 멤버 함수 정의
void Warrior::IncreaseHP(int inc_hp) {  
    hp += inc_hp;
}

void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

int Warrior::GetHP() const {
    return hp;
}

void Warrior::DoAttack() {
    cout << "베기 사용" << endl;
}

// Magician 클래스의 멤버 함수 정의
void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

int Magician::GetHP() const {
    return hp;
}

void Magician::DoAttack() {
    cout << "마법 사용" << endl;
}



