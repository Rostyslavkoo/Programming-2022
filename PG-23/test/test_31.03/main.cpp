#include <iostream>

using namespace std;

struct A {
    char i;
    A() : i ('v') { cout << "AV" << i; }
    A(char ii) : i(ii) { cout << "A" << i; }
    };
    struct B: virtual A {
        B() { cout << "BV";}
    B(char ii) :A(ii){ cout << "B" << i; }
    };
    struct D : virtual A {
        D() {cout << "DV";}
    D(char ii) :A(ii){ cout << "D" << i; }
};
struct E : B, D {
    E (char ii) :A(ii),B(ii),D(ii){cout << "E" << i; }
};
void F() {
    E e('y');
}
int  main(){
    F();
}