
#include <iostream>
#include <cmath>

using namespace std;

int main()
{    int circumR;
     float pi = 3.14;

    cout << "Radius\n->";
    cin >> circumR;

    float circumL = 2 * pi * circumR;
    float circumS = pi * pow(circumR, 2);
    float circumV = 4 / 3 * (pi * pow(circumR, 3));

    cout << endl;
    cout << "Circum L ->\t" << circumL << endl;
    cout << "Circum S ->\t" << circumS << endl;
    cout << "Circum V ->\t"<< circumV << endl;

    return 0;
}
