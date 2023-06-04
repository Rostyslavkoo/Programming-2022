#include <iostream>
using namespace std;

struct A {
        char i;
        A() :i('0') { cout << "F" << i; }
        A(const A& a) : i(a.i) { cout << "AC" << i; }
        A(char ii) :i(ii) { cout << "A" << i; }
};

struct B : virtual A {
    B() {}
    B(const B& b) { cout << "BC" << i; }
    B(char ii) { cout << "B" << i; }
};
struct D : virtual A {
    D() {}
    D(const D& d) { cout << "DC" << i; }
    D(char ii) { cout << "D" << i; }
};
struct E : B, D {
    E(char ii) { }
};
void F() {
    E e('a');
}

int main() {
F();
    return 0;
}
