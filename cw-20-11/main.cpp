#include <iostream>
#include <string>
using namespace std;

struct  Employee
{
    int id;
    string name;
    double salary;
};
void print (Employee employee){
    cout << employee.id << endl;
    cout << employee.name << endl;
    cout << employee.salary << endl;
}
int main()
{
    Employee john = {1, "john" ,100};
    print(john);
    return 0;
}