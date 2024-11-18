#include <iostream>
using namespace std;

class A{
public:
    friend class B; //B는A의프렌드가된다.
    A(string s = "") : secret{s} { }
private:
    string secret; //B는여기에접근할수있다.
};
class B{
public:
    B( ){ }
    void print(A obj){
        cout<<obj.secret<<endl;
    }
};
int main()
{
    A a("이것은 기밀 정보 입니다.");
    B b;
    b.print(a);
    return 0;
}