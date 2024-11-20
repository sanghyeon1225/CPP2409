#include "user.h"

User::User() {
    hp = 20;
    itemCnt = 0;
    xpos = 0;
    ypos = 0;
}
void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
int User::GetHP(){
    return hp;
}
void User::DoAttack() {
    cout << "공격합니다" << endl;
}

void Warrior::DoAttack() {
    cout << "베기 사용" << endl;
}

void Magician::DoAttack() {
    cout << "마법 사용" << endl;
}