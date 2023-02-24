//Визначити клас Товар з полями назва, конструктором дефолтним та операторами зсуву вліво та вправо, методами get та set доступу до поля.
//
//Визначити клас Склад полями: динамічний масив товарів, кількість товарів, номер складу, адреса складу. В класі визначити конструктори
//дефолтний, копіювання, з параметрами, оператор присвоєння, індексування, деструктор, оператор зсуву вліво та вправо, а також методи get та set доступу до полів.
//
//Ввести дані про два склади. Видрукувати дані про ці склади у алфавітному порядку адрес. Вивести список товарів, в яких склад має
//менший номер. Створити новий склад, скопіювавши його зі складу, кількість товарів в якому є менша.

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
public:
    Product() : name("") {}
    Product(string n) : name(n) {}
    Product(Product& newPR) : name(newPR.name) {}


    friend ostream& operator<<(ostream& os,  Product& product) {
        os << product.name;
        return os;
    }

    friend istream& operator>>(istream& is, Product& product) {
        is >> product.name;
        return is;
    }

    string getName() {
        return name;
    }

    void setName(string n) {
        name = n;
    }
};
class Warehouse {
private:
    Product *products;
    int count;
    int id;
    string address;
public:
    Warehouse() : products(), count(0), id(0), address(""){}
    Warehouse(Product* p, int c, int i, string a) :
    products(p), count(c), id(i), address(a) {}

    Warehouse(int count, int id, string address) : products(new Product[count]), count(count), id(id), address(address) {}
    Warehouse(const Warehouse& newPR) : products(new Product[newPR.count]), count(newPR.count), id(newPR.id), address(newPR.address) {
        for (int i = 0; i < count; i++) {
            products[i] = newPR.products[i];
        }
    }

    int getCount()
    {
        return count;
    }
    void setCount(int c)
    {
        count = c;
    }
    int getId()
    {
        return id;
    }
    void setId(int i) {
        id = i;
    }
    string getAddress()
    {
        return address;
    }
    void setAddress(string a)
    {
        address = a;
    }
    void setProducts(int i, Product pr)
    {
    if (i >= 0 && i < 5) {
        products[i] = pr;
    }

    }

    void getProducts()
    {
        for(int i = 0; i<= getCount(); i++){
           cout <<  products[i].getName() << "\n";
        }
    }
};


int main(){
    Product pr1("Product1");
    Product pr2("Product2");
    Product pr3("Product3");

    Product* Products = new Product[5];
    Products[0] = pr1;
    Products[1] = pr2;
    Products[2] = pr3;

    Product* Products2 = new Product[5];
    Products2[1] = pr1;
    Products2[2] = pr2;
    Products2[0] = pr3;


    Warehouse w1(Products,5,1,"address1");
    Warehouse w2(Products2,10,2,"address2");

    if(w1.getId() < w2.getId()){
        w1.getProducts();

    }else{
        w2.getProducts();
    }
    Warehouse w3 = w1.getCount() < w2.getCount() ? w1 : w2;




    return 0;
}
