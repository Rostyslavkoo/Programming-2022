// Визначити шаблонний клас Товар, для зберігання даних про деякий об’єкт Т,
// дату його виготовлення та термін придатності (в днях). В класі визначити оператори<< і >>,
// метод, який повертає дату кінцевого терміну придатності. Також визначити структуру Молоко з
// полями назва та жирність, оператори<< і >>. Створити два масиви Товарів з шаблонними параметрами string
// та Молоко. Ввести дані про декілька таких об’єктів і видрукувати для кожного кінцевий термін придатності.

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Product
{
private:
    T object;
    int daysProd;
    const int Expiration;

public:
    Product() : Expiration(28){}
    Product(T object, int daysProd) : object(object), daysProd(daysProd), Expiration(28){}

    friend ostream& operator<<(ostream& os, const Product& p){
        os << "Object: " << p.object << endl;
        os << "Days Since Production: " << p.daysProd << endl;
        os << "Expiration Days: " << p.Expiration << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Product& p)
    {
        is >> p.object >> p.daysProd;
        return is;
    }

    int getExpiration() const
    {
        return Expiration;
    }

    int getdaysProd() const
    {
        return daysProd;
    }

    bool isExpired(int currentDay) const
    {
        return currentDay - daysProd >= Expiration;
    }
};

struct Milk{
    string name;
    double fat;

    friend istream& operator>>(istream& is, Milk& m){
        is >> m.name >> m.fat;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Milk& m){
        os << "Name: " << m.name << endl;
        os << "Fat: " << m.fat << endl;
        return os;
    }


};

int main()
{
    Product<string> products[1];
    Product<Milk> milks[1];

    for (int i = 0; i < 1; i++){
        cout << "Enter Product " << i+1 << " Name and Days Since Production: ";
        cin >> products[i];

        cout << "Enter Milk " << i+1 << " Name, Fat and Days Since Production: ";
        cin >> milks[i];
    }

    int currentDay = 28;
    for (int i = 0; i < 1; i++){
        cout << products[i];
        if (products[i].isExpired(currentDay)){
            cout << "This product is expired." << endl;
        }
        else{
            cout << "This product will expire in " << products[i].getExpiration() - (currentDay - products[i].getdaysProd()) << " days." << endl;
        }

        cout << milks[i];
        if (milks[i].isExpired(currentDay)){
            cout << "This milk is expired." << endl;
        }
        else{
            cout << "This milk will expire in " << milks[i].getExpiration() - (currentDay - milks[i].getdaysProd()) << " days." << endl;
        }
    }

    return 0;
}