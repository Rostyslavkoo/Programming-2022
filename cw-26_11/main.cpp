#include <iostream>
#include <fstream>
using  namespace std;
struct Point {
    int x;
    int y;
    friend istream & operator >> (istream & is, Point & point){
//        cout << "Enter x";
        is >> point.x;

//        cout << "Enter y";
        is >> point.y;
        return is;
    }
    friend ostream & operator << (ostream & os, Point & point){
        os << "X =" << point.x << endl;
        os << "Y =" << point.y << endl;

        return os;
    }

};
class Circle{
    Point center;
    int radius;
public:
    Circle(): center(), radius(0) {};
    Circle(Point _center,int _radius) : center(_center),radius(_radius){};
    Circle(const Circle &circle) : center(circle.center), radius(circle.radius) {};
    friend istream & operator >> (istream & is, Circle & circle){
//        cout << "Enter radius";
        is >> circle.radius;

//        cout << "Enter center";
        is >> circle.center;
        return is;
    }
    friend ostream & operator << (ostream & os, Circle & circle){
        os << "radius =" << circle.radius << endl;
        os << "center =" << circle.center << endl;

        return os;
    }

};
int main() {
    Circle circle;
    cin >> circle;
    cout << circle;

    ofstream ofs("data1.txt");

    fstream ifs;
    ifs.open("data1.txt");
    ifs >> circle;
    ifs.close();

    ofs << circle;
    ofs.close();
    return 0;
}
