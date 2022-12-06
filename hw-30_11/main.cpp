#include <iostream>

using namespace std;

struct  Point {
    double x,y;
};

class  Line{
    double a,b,c;
    friend ostream& operator<<(ostream& os, Point& point) {
        os  << "x,y = " << point.x << point.y;
        return os;
    }
public:
    Line() : a(0),b(0),c(0) {}
    Line(double _a,double _b, double _c) : a(_a), b(_b), c(_c) {}
    Line (const Line & line) : a(line.a),  b(line.b),  c(line.c) {}

    friend istream& operator>>(istream& is, Line& line) {
        cout << "Enter numbers" << endl;
        is >> line.a >> line.b >> line.c;

        return is;
    }

    friend ostream& operator<<(ostream& os, Line& line) {
        os  << "numbers = " << line.a << line.b << line.c << endl;
        return os;
    }
    Point getIntersectionPoint(Line myLine) {
        double resX;
        double resY;
        double denom = a * myLine.b - b * myLine.a;
        resX = (b * myLine.a - myLine.b * a) / denom;
        resY = (c * myLine.a - myLine.c * a) / denom;
        Point res = {resX, resY};
        return res;
    }
    bool isIntersect(Line myLine){
        double denom = a * myLine.b - b * myLine.a;
        return  denom != 0;
    }


};

int main() {
    const int n = 3;
Line * lines = new Line[n];
for (int i = 0; i <n ; i++)
{
    cin >> lines[i];
}
    for (int i = 0; i <n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
           if(lines[i].isIntersect(lines[j])){
               Point myPoint = lines[i].getIntersectionPoint(lines[j]);
               cout << lines[i] << endl;
               cout << lines[j] << endl;
               cout << myPoint.x  << "\t" << myPoint.y << endl;
           }else{
               cout << lines[i] << endl;
               cout << lines[j] << endl;
               cout << "not intersect" << endl;
           }
        }

    }

   return 0;
}
